#include <bits/stdc++.h>
#include "LexAnalysis.cpp"
#include "tokens.h"
// #include "node.h"
// #include "productions.h"
#include "utils.h"

using namespace std;

struct SynError
{
    int line;    // ������������
    string type; // ��������
    string x;    // ����ջ������
    string a;    // �����������
    SynError(int l, string type, string x, string a)
    {
        this->line = l;
        this->type = type;
        this->x = x;
        this->a = a;
    }
    void show()
    {
        cout << type << " occurs at " << line << " when stack_top is " << x << " and input is " << a << endl;
    }
};

struct ASTNode
{
    ASTNode *parent;
    // ASTNode *next_sibling;      // ��һ���ֵܽڵ�
    int code;                   // ÿ���ڵ��Ψһ��ʶ��
    vector<ASTNode *> children; // �ӽڵ�
    string label;               // ��Ӧ�ս��/���ս��
    void set(string l, int c)
    {
        this->label = l;
        this->parent = nullptr;
        this->code = c;
        // this->next_sibling = nullptr;
    }
};
class AST
{
private:
    ASTNode *root;

public:
    void init(ASTNode *root)
    {
        this->root = root;
    }
    void insert(ASTNode *p, ASTNode *c)
    {
        c->parent = p;
        // p->children[-1]->next_sibling = c;
        p->children.push_back(c);
    }
    void show(ASTNode *root)
    {
        cout << "CODE: " << root->code << " ";
        if (root->parent != nullptr)
            cout << "PARENT: " << root->parent->label << " ";
        cout << "LABLE: " << root->label << " ";
        cout << "CHILDREN: ";
        for (auto i : root->children)
        {
            cout << i->code << " ";
        }
        cout << endl;
        for (auto i : root->children)
        {
            show(i);
        }
    }
    void generateGRAPH()
    {
        cout << "GRAPHVIZ CODE:" << endl;
        cout << "digraph G {" << endl;
        DFS(root);
        cout << "}" << endl;
    }
    void DFS(ASTNode *root)
    {
        cout << "node" << root->code << "[label=\"" << root->label << "\"];" << endl;
        for (auto i : root->children)
        {
            DFS(i);
            cout << "node" << root->code << "->"
                 << "node" << i->code << ";" << endl;
        }
    }
};

class LL1
{
private:
    vector<string> token_list;
    vector<node> elements;
    map<string, set<string>> first_map;
    map<string, set<string>> follow_map;
    map<string, vector<production>> pros; // map<non terminal symbol on the left, production>
    map<string, map<string, production>> pre_table;
    stack<string> ana_stack;     // ����ջ
    vector<string> buffer;       // ���뻺����
    vector<SynError> error_list; // ���ִ�������봮�еķ���
    ASTNode *root;               // �﷨���������ڵ�
    AST tree;                    // �﷨������
    vector<production> history;  // ����ʽʹ�ü�¼
    int index;                   // ����ʽʹ����ʷ�±�
    int code;                    // ��ǰ�ڵ����

public:
    LL1(vector<string> tl, vector<node> e)
    {
        token_list = tl;
        elements = e;
        initProduction();
        getFIRSTset();
        getFOLLOWset();
        getPredictTable();
        analysis();
        getASTree();
        show();
        tree.generateGRAPH();
    }

    void insertFIRST(string left, string cur_symbol)
    {
        if (first_map[cur_symbol].size() == 0)
        {
            getFIRST(cur_symbol);
        }
        for (auto iter : first_map[cur_symbol])
        {
            if (iter != "none")
                first_map[left].insert(iter);
        }
    }

    void getFIRST(string left)
    {
        vector<production> pro = pros[left];
        for (int i = 0; i < pro.size(); ++i)
        {
            string cur_symbol = pro[i].right[0]; // ����ʽ�Ҳ��һ������
            // ���÷���Ϊ�ս��
            if (isTERMINAL(cur_symbol))
            {
                first_map[left].insert(cur_symbol);
            }
            else if (isNON_TERMINAL(cur_symbol))
            {
                insertFIRST(left, cur_symbol);
                for (size_t j = 0; j < pro[i].right.size(); j++)
                {
                    // ��ǰ���ſ���ָ���ʱ
                    // Y1...Yj-1 -> none �� FIRST(Yj)����FIRST(X)
                    int flag = 0;                           // ��ʾ��ǰ�����Ƿ����ָ��none
                    for (auto iter : pros[pro[i].right[j]]) // production iter
                    {
                        if (iter.right[0] == "none")
                        {
                            if (j != pro[i].right.size() - 1)
                                insertFIRST(left, pro[i].right[j + 1]);
                            else // ���ڲ���ʽ��ĩ����
                            {
                                first_map[left].insert("none"); // ��none����FIRST(X)
                            }
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0)
                    {
                        break; // ����ǰ���Ų���ָ��none���ټ����ж�
                    }
                }
            }
        }
    }

    void insertFOLLOWbyFIRST(string b, string a)
    {
        // cout << "insert first of " << a << " to " << b << endl;
        // ��FIRST(a)-none����FOLLOW(b)
        for (auto iter : first_map[a])
        {
            if (iter != "none")
            {
                follow_map[b].insert(iter);
            }
        }
    }

    void insertFOLLOWbyFOLLOW(string b, string a)
    {
        // cout << "insert follow of " << a << " to " << b << endl;
        // ��FOLLOW(a)����FOLLOW(b)
        for (auto iter : follow_map[a])
        {
            follow_map[b].insert(iter);
        }
    }

    void getFOLLOW(production p)
    {
        int flag = 0; // ��ʾ��̷����Ƿ����ָ���
        for (int i = p.right.size() - 1; i >= 0; i--)
        {
            string cur_symbol = p.right[i];
            if (isNON_TERMINAL(cur_symbol))
            {
                // ����һ�����ſ���ָ���ʱ����FOLLOW(A)����FOLLOW(B)
                if (flag == 1)
                {
                    insertFOLLOWbyFOLLOW(cur_symbol, p.left);
                }
                flag = 0;
                // ���ڲ���ʽ���һ�����ս��B����FOLLOW(A)����FOLLOW(B)
                if (i == p.right.size() - 1)
                {
                    insertFOLLOWbyFOLLOW(cur_symbol, p.left);
                }
                // ����A->aBb�Ĳ���ʽ����FIRST(b)-none����FOLLOW(B)
                else
                {
                    insertFOLLOWbyFIRST(cur_symbol, p.right[i + 1]);
                }
                // �жϵ�ǰ�����Ƿ����ָ���
                for (auto iter : pros[cur_symbol])
                {
                    if (iter.right[0] == "none")
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            else if (isTERMINAL(cur_symbol))
            {
                // �ս������ָ���
                flag = 0;
            }
        }
    }

    void initProduction()
    {
        for (auto iter : productions)
        {
            production p(iter);
            if (pros.find(p.left) != pros.end())
            { // map���Ѿ�����key�����
                pros[p.left].push_back(p);
            }
            else
            { // map�в�����key�����
                vector<production> temp;
                temp.push_back(p);
                pros.insert(pair<string, vector<production>>(p.left, temp));
            }
        }
    }

    void getFIRSTset() // ����FIRST����map
    {
        // ���ɷ��ս����first_map�еĶ�Ӧλ��
        for (auto iter : NON_TERMINAL_LIST)
        {
            string left = iter;
            set<string> temp;
            first_map.insert(pair<string, set<string>>(left, temp));
        }
        // �����ս����FIRST��
        for (auto iter : TERMINAL_LIST)
        {
            string left = iter;
            set<string> temp;
            temp.insert(left);
            first_map.insert(pair<string, set<string>>(left, temp));
        }
        // ����FIRST��
        for (auto iter : pros)
        {
            if (first_map[iter.first].size() == 0)
            {
                getFIRST(iter.first);
            }
        }
    }

    void getFOLLOWset()
    {
        // ���ɷ��ս����follow_map�ж�Ӧ��λ��
        for (auto iter : NON_TERMINAL_LIST)
        {
            set<string> temp;
            if (iter == "S")
                temp.insert("$");
            follow_map.insert(pair<string, set<string>>(iter, temp));
        }
        map<string, set<string>> comp;
        // ��������ʽ����FOLLOW����ֱ�����ϲ��ٱ仯
        do
        {
            comp = follow_map;
            for (auto iter : pros)
            {
                for (auto iter1 : iter.second)
                {
                    production p = iter1;
                    getFOLLOW(p);
                }
            }
        } while (!(CompareMap(comp, follow_map)));
    }

    bool check() // ����Ƿ�����ķ�����
    {
        // �Ƿ񲻺���ݹ�
        for (auto iter : pros)
        {
            for (auto p : iter.second)
            {
                if (p.left == p.right[0])
                    return false;
            }
        }
        // �ս�����Ƿ��������ཻ
    }

    void analysis()
    {
        cout << "Syntax Analysis Start!" << endl;
        ana_stack.push("S");
        for (auto e : elements)
        {
            while (!ana_stack.empty())
            {
                string a = e.terminal; // �������a
                while (!ana_stack.empty() && ana_stack.top() == "none")
                {
                    cout << "Replace None" << endl;
                    ana_stack.pop();
                }
                if (ana_stack.empty())
                    break;
                string x = ana_stack.top(); // ջ������x
                stack<string> temp = ana_stack;
                cout << "x: " << x << ", a: " << a << endl;
                cout << "stack: ";
                while (!temp.empty())
                {
                    cout << temp.top() << " ";
                    temp.pop();
                }
                cout << endl;
                try
                {
                    if (isTERMINAL(x))
                    {
                        if (x == a)
                        {
                            cout << "Pop Success" << endl;
                            ana_stack.pop();
                            break;
                        }
                        else
                        {
                            cout << "TokenMatchError" << endl;
                            // throw("GrammerError");
                            SynError error(e.line, "TokenMatchError", x, a);
                            error_list.push_back(error);
                            ana_stack.pop();
                        }
                    }
                    else if (isNON_TERMINAL(x))
                    {
                        production p = pre_table[x][a];
                        p.show();
                        if (p.str != "")
                        {
                            history.push_back(p);
                            ana_stack.pop();
                            for (auto iter = p.right.rbegin(); iter != p.right.rend(); iter++)
                            {
                                ana_stack.push(*iter);
                            }
                        }
                        else
                        {
                            cout << "ProductionMatchError" << endl;
                            SynError error(e.line, "ProductionMatchError", x, a);
                            error_list.push_back(error);
                            ana_stack.pop();
                        }
                    }
                    else
                    {
                        cout << "TokenMatchError" << endl;
                        // throw("GrammerError");
                        SynError e(e.line, "TokenMatchError", x, a);
                        error_list.push_back(e);
                        break;
                    }
                }
                catch (string exception)
                {
                    if (exception == "GrammerError")
                    {
                        cout << "ERROR: Grammer Error Occurs at Line " + to_string(e.line) + " ---- " + e.msg << endl;
                    }
                    else if (exception == "MatchError")
                    {
                        cout << "ERROR: No Productions Could Match From " + x + " to " + a << endl;
                    }
                    // error_list.push_back(a);
                    // continue;
                    break;
                }
            }
        }
        cout << endl;
        if (ana_stack.empty())
        {
            cout << error_list.size() << " Errors Occured." << endl;
            cout << "Syntax Analysis Succeed!" << endl;
        }
    }

    void insertPredictTable(string n, string t, production p)
    {
        if (pre_table[n][t].str == "")
            pre_table[n][t] = p;
        else if(pre_table[n][t].right[0]=="none")
            pre_table[n][t] = p;
    }

    void getPredictTable()
    {
        // ��ʼ��Ԥ�������
        for (auto non_terminal : NON_TERMINAL_LIST)
        {

            map<string, production> t_p;
            for (auto terminal : TERMINAL_LIST)
            {
                production p;
                t_p.insert(pair<string, production>(terminal, p));
            }
            pre_table.insert(pair<string, map<string, production>>(non_terminal, t_p));
        }
        // ����Ԥ�������
        for (auto iter : pros)
        {
            for (auto p : iter.second)
            {
                if (isTERMINAL(p.right[0]))
                {
                    if (p.right[0] != "none")
                    {
                        insertPredictTable(p.left, p.right[0], p);
                    }
                    else
                    {
                        // ������FOLLOW��
                        for (auto follow : follow_map[p.left])
                        {
                            insertPredictTable(p.left, follow, p);
                        }
                    }
                }
                else if (isNON_TERMINAL(p.right[0]))
                {
                    // �����ײ����ս��FIRST��
                    for (auto first : first_map[p.right[0]])
                    {
                        insertPredictTable(p.left, first, p);
                    }
                }
            }
        }
    }

    void getASTree()
    {
        cout << "INIT AST......" << endl;
        root = new ASTNode;
        this->code = 0;
        root->set("S", code);
        tree.init(root);
        index = 0;
        DFS(root);
    }
    void DFS(ASTNode *root)
    {
        // cout << index << endl;
        // cout << "root: " << root->label << endl;
        production p;
        if (index < history.size())
        {
            p = history[index];
            p.show();
        }
        else
            return;
        vector<string> right = p.right;
        for (auto i : right)
        {
            ASTNode *temp = new ASTNode;
            code++;
            temp->set(i, code);
            // cout << "child: " << i << endl;
            tree.insert(root, temp);
            if (isNON_TERMINAL(i))
            {
                index++;
                DFS(temp);
            }
        }
    }

    void show()
    {
        cout << "PRODUCTIONS:" << endl;
        for (auto iter : pros)
        {
            for (auto iter1 : iter.second)
            {
                iter1.show();
            }
        }
        cout << "FIRST SET" << endl;
        for (auto iter : first_map)
        {
            cout << iter.first << ": ";
            cout << "{ ";
            for (auto iter1 : iter.second)
            {
                cout << iter1 << " ";
            }
            cout << "}" << endl;
        }
        cout << "FOLLOW SET" << endl;
        for (auto iter : follow_map)
        {
            cout << iter.first << ": ";
            cout << "{ ";
            for (auto iter1 : iter.second)
            {
                cout << iter1 << " ";
            }
            cout << "}" << endl;
        }
        // ���Ԥ�������
        // ����&����
        int row = NON_TERMINAL_LIST.size();
        int col = TERMINAL_LIST.size() + 1;
        // �����ͷ
        vector<string> D;
        D.push_back(" ");
        for (auto iter : TERMINAL_LIST)
        {
            D.push_back(iter);
        }
        // ������ͷ
        vector<string> R;
        for (auto iter : NON_TERMINAL_LIST)
        {
            R.push_back(iter);
        }
        // ��������п�
        vector<int> max;
        max.push_back(5);
        for (auto i : TERMINAL_LIST)
        {
            int maxlen = (i.length() > 1) ? i.length() : i.length() + 1;
            for (auto j : NON_TERMINAL_LIST)
            {
                if (pre_table[j][i].str.length() > maxlen)
                    maxlen = pre_table[j][i].str.length();
            }
            max.push_back(maxlen);
        }
        // ���������
        vector<vector<string>> Str;
        for (int i = 0; i < row; i++)
        {
            vector<string> temp;
            string n = R[i]; // ���ս��
            temp.push_back(n);
            for (int j = 1; j < col; j++)
            {
                string t = D[j]; // �ս��
                temp.push_back(pre_table[n][t].str);
            }
            Str.push_back(temp);
        }
        // ����Ԥ�������
        Draw_Datas(max, Str, D, col, row);

        // for (auto i : history)
        // {
        //     i.show();
        // }
        if (error_list.size() > 0)
        {
            for (auto e : error_list)
            {
                e.show();
            }
        }
        tree.show(root);
    }
};

int main()
{
    cout << "TEST START!" << endl;
    // ASTNode root;
    // root.set("S");
    // ASTNode node1;
    // node1.label = "A";
    // ASTNode node2;
    // node2.label = "B";
    // AST tree;
    // tree.init(&root);
    // tree.insert(&root, &node1);
    // tree.insert(&root, &node2);
    // tree.show(&root);

    LexAnalysis la("error_test.c");
    la.analysis();
    la.showResult();
    vector<string> tl;
    vector<node> e = la.elements;
    node n("$");
    e.push_back(n);
    LL1 l(tl, e);
}