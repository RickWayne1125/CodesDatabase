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
    // �﷨�Ƶ�������������
    string token;  // Ϊ�ս��ʱ�ı�־��ͬʱҲ������Ϊ���ű����ָ��token map�е�λ��
    int type;      // �ýڵ�����ʾ������
    int int_val;   // �ýڵ������ֵ
    bool bool_val; // �ýڵ�Ĳ���ֵ
    int line;      // �ýڵ���������
    int reg;       // ��Ӧ����ʱ�Ĵ������

    void set(string l, int c, string t = "")
    {
        this->label = l;
        this->parent = nullptr;
        this->code = c;
        this->token = t;
        // this->next_sibling = nullptr;
    }
    void set(string t)
    {
        this->token = t;
    }
    void set(node element)
    {
        this->token = element.msg;
        this->type = element.value;
        this->line = element.line;
    }
    void setValue(int i)
    {
        int_val = i;
    }
    void setValue(bool b)
    {
        bool_val = b;
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
        string label = (root->token == "") ? root->label : root->token;
        cout << "node" << root->code << "[label=\"" << label << "\"];" << endl;
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
    // vector<string> token_list;
    map<string, node> token_map;
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
    // �﷨�Ƶ�������������
    vector<string> terminal_history; // �ս��ƥ����ʷ
    int index2;                      // �ս���±�
    // Ŀ�����������������
    int reg_index;         // ��ǰ���Ĵ������
    vector<string> mips;   // MIPSָ��
    map<string, int> regs; // �Ĵ�����ӳ���keyΪ����/��ʶ����valueΪ�Ĵ������
    int last_address;      // ���һ�β����ĵ�ַ������goto��

public:
    LL1(vector<node> e, map<string, node> tm)
    {
        // token_list = tl;
        elements = e;
        token_map = tm;
        reg_index = 0;
        initProduction();
        getFIRSTset();
        getFOLLOWset();
        getPredictTable();
        analysis();
        getASTree();
        index = 0;
        translate(root);
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
                string t = e.msg;      // ��Ӧ��ʵ�ʷ���
                cout << e.line << endl;
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
                            terminal_history.push_back(t);
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
                        cout << "TokenError" << endl;
                        // throw("GrammerError");
                        SynError e(e.line, "TokenError", x, a);
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
                cout << endl;
            }
        }
        if (ana_stack.empty())
        {
            cout << error_list.size() << " Errors Occured." << endl;
            cout << "Syntax Analysis Succeed!" << endl
                 << endl;
        }
    }

    void insertPredictTable(string n, string t, production p)
    {
        if (pre_table[n][t].str == "")
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
                        cout << p.right[0] << endl;
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

    void translate(ASTNode *root)
    {
        production p = history[index];
        string left = p.left;
        vector<string> right = p.right;
        getTarget();                   // ���Ƚ������ͳ����ļĴ��������
        int address = mips.size() - 1; // ��ǰָ��ĵ�ַ
        // �ȱ�������ÿ���ӽ������ԣ�ͬʱȷ�ϱհ��Ƿ��걸
        int cnt1 = 0; // {}�Ƿ��걸��Ϊ0��ʾ�걸
        int cnt2 = 0; // ()�Ƿ��걸��Ϊ0��ʾ�걸
        int cnt3 = 0; // []�Ƿ��걸��Ϊ0��ʾ�걸
        // ����ǰ�ڵ������ʱ�Ĵ���
        if (root->token == "id")
        {
            root->reg = token_map[root->label].reg;
        }
        else
        {
            root->reg = reg_index;
            reg_index++;
        }
        // ���ȼ���̳�����
        int type;
        for (auto it : root->children)
        {
            // �������������ʱ
            if (p.right[0] == "type")
            {
                if (root->children[0]->token == "int")
                {
                    type = INTEGER;
                }
                else if (root->children[0]->token == "bool")
                {
                    type = BOOLEAN;
                }
                root->type = type;
                if (it->type == IDENTIFIER)
                {
                    // ����Ҳ�Ϊ�����������ű�
                    if (token_map[it->token].type < 0) // Ĭ�Ϲ���ʱ��node->typeС��0�����type����0�������������
                    {
                        token_map[it->token].type = type;
                    }
                    else // �����ظ�����
                        cout << "Variable duplicate declaration! Error of " << it->label << " at line: " << it->line << endl;
                }
            }
            if (isNON_TERMINAL(it->label))
            {
                ASTNode *temp = it;
                index++;
                translate(temp);
            }
            else
            {
                if (it->label == "{")
                {
                    cnt1++;
                }
                else if (it->label == "}")
                {
                    cnt1--;
                }
                else if (it->label == "(")
                {
                    cnt2++;
                }
                else if (it->label == ")")
                {
                    cnt2--;
                }
                else if (it->label == "[")
                {
                    cnt3++;
                }
                else if (it->label == "]")
                {
                    cnt3--;
                }
            }
        }
        if (cnt1 > 0)
        {
            cout << "Missing \'}\' at line: " << root->line << endl;
        }
        else if (cnt1 < 0)
        {
            cout << "Missing \'{\' at line: " << root->line << endl;
        }
        if (cnt2 > 0)
        {
            cout << "Missing \')\' at line: " << root->line << endl;
        }
        else if (cnt2 < 0)
        {
            cout << "Missing \'(\' at line: " << root->line << endl;
        }
        if (cnt3 > 0)
        {
            cout << "Missing \']\' at line: " << root->line << endl;
        }
        else if (cnt3 < 0)
        {
            cout << "Missing \'[\' at line: " << root->line << endl;
        }
        // �����������ۺ�����
        // �����ָ�ֵ����ʱ��
        else if (p.str == PRO_EQUAL)
        {
            string MIPS = "LI reg" + to_string(root->children[0]->reg) + ", reg" + to_string(root->children[1]->reg);
            mips.push_back(MIPS);
        }
        // ������A->idʱ
        else if (p.str == PRO_ID_A)
        {
            string MIPS = "MOVE reg" + to_string(token_map[root->children[0]->label].reg) + ", reg" + to_string(root->reg);
            mips.push_back(MIPS);
        }
        // ������һ��������ʱ
        else if (p.str == PRO_EXP_ID || p.str == PRO_EXP_NUM)
        {
            // ������������
            // ����һ�������������Ϣ
            if (p.right[0] == "id" || p.right[0] == "num")
            {
                if (root->children[0]->type != root->children[1]->type && root->children[1]->type >= 0 && root->children[0]->type >= 0)
                {
                    cout << "Cannot operate variables of different types! Error between " << root->children[0]->token << " and " << root->children[1]->label << " at line: " << root->children[0]->line << endl;
                }
            }
            // �Ը��ڵ�����ͽ��и���
            root->type = root->children[0]->type;
            string MIPS = "MOVE reg" + to_string(root->reg) + ", reg" + to_string(root->children[0]->reg);
            mips.push_back(MIPS);
        }
        // �����ּ���հ�ʱ
        else if (p.left == "B'")
        {
            root->type = (root->children.size() == 1) ?: root->children[1]->type;
            if (root->children.size() == 1)
            {
                // ���Ҳ�ֻ����������򱨴���ʧ������
                if (root->children[0]->label == "+" || root->children[0]->label == "-" || root->children[0]->label == "*" || root->children[0]->label == "/" || root->children[0]->label == "|" || root->children[0]->label == "&")
                {
                    cout << "Missing Operate Number at line: " << root->line << endl;
                }
                // ���Ҳ�ֻ�б�ʶ�����򱨴���ʧ�����
                else if (root->token == "id")
                {
                    cout << "Missing Operator at line: " << root->line << endl;
                }
            }
            if (p.right[0] == "+")
            {
                string MIPS = "ADD reg" + to_string(root->reg) + ", reg" + to_string(root->children[0]->reg) + ", reg" + to_string(root->children[1]->reg);
                mips.push_back(MIPS);
            }
            else if (p.right[0] == "-")
            {
                string MIPS = "SUB reg" + to_string(root->reg) + ", reg" + to_string(root->children[0]->reg) + ", reg" + to_string(root->children[1]->reg);
                mips.push_back(MIPS);
            }
            else if (p.right[0] == "*")
            {
                string MIPS = "MUL reg" + to_string(root->reg) + ", reg" + to_string(root->children[0]->reg) + ", reg" + to_string(root->children[1]->reg);
                mips.push_back(MIPS);
            }
            else if (p.right[0] == "/")
            {
                string MIPS = "DIV reg" + to_string(root->reg) + ", reg" + to_string(root->children[0]->reg);
                mips.push_back(MIPS);
                MIPS = "MFLO reg" + to_string(root->parent->reg);
            }
            else if (p.right[0] == "==")
            {
                string MIPS = "BEQ reg" + to_string(root->reg) + ", reg" + to_string(root->children[0]->reg), last_address;
                mips.push_back(MIPS);
            }
            else if (p.right[0] == "<=")
            {
                string MIPS = "BLE reg" + to_string(root->reg) + ", reg" + to_string(root->children[0]->reg), last_address;
                mips.push_back(MIPS);
            }
            else if (p.right[0] == ">=")
            {
                string MIPS = "BGE reg" + to_string(root->reg) + ", reg" + to_string(root->children[0]->reg), last_address;
                mips.push_back(MIPS);
            }
            else if (p.right[0] == "!=")
            {
                string MIPS = "BNE reg" + to_string(root->reg) + ", reg" + to_string(root->children[0]->reg), last_address;
                mips.push_back(MIPS);
            }
            else if (p.right[0] == "<")
            {
                string MIPS = "BLT reg" + to_string(root->reg) + ", reg" + to_string(root->children[0]->reg), last_address;
                mips.push_back(MIPS);
            }
            else if (p.right[0] > ">")
            {
                string MIPS = "BGT reg" + to_string(root->reg) + ", reg" + to_string(root->children[0]->reg), last_address;
                mips.push_back(MIPS);
            }
        }
        // ������ʽָ�򵥶��ı�ʶ������ʱ
        else if (p.right.size() == 1)
        {
            if (p.right[0] == "id")
            {
                root->type = token_map[root->children[0]->label].type;
            }
            // else if (p.right[0] == "num")
            // {
            //     root->type =
            // }
        }
        else if (p.str == PRO_EXP_WHILE)
        {
            string go_back = "J " + address;
            last_address = address;
            int label = last_address;
            mips.push_back(to_string(label) + ":");
            translate(root->children[2]); // ����������
            translate(root->children[5]); // ����ִ�п�
            mips.push_back(go_back);
        }
        else if (p.str == PRO_EXP_IF || p.str == PRO_EXP_IF_ELSE)
        {
            last_address = address + 2;
            int label = address;
            mips.push_back(to_string(label) + ":");
            translate(root->children[2]); // ����������
            translate(root->children[5]); // ����ִ�п�
        }
        else if (p.str == PRO_GET || p.str == PRO_PUT)
        {
            string MIPS = "SYSCALL";
            mips.push_back(MIPS);
        }
        // ������ʱ�����Ĵ���
        if (isNON_TERMINAL(root->token))
        {
            reg_index = root->reg;
            regs.erase(root->token);
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
        index2 = 0;
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
        // �����ӽ��
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
            else if (isTERMINAL(i) && i != "none")
            {
                // if (index2 < terminal_history.size())
                temp->set(elements[index2]);
                index2++;
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
        for (auto it : mips)
        {
            cout << it << endl;
        }
    }
    void getTarget()
    {
        // ����Ϊ��������Ĵ���
        for (auto it : elements)
        {
            if (it.terminal == "num")
            {
                regs.insert(pair<string, int>(it.msg, reg_index));
                string MIPS = "LI reg" + to_string(reg_index) + ", " + it.msg;
                mips.push_back(MIPS);
                reg_index++;
            }
        }
        // ֮��Ϊ�����ı�������Ĵ���
        // for (auto it : token_map)
        // {
        //     it.second.reg = reg_index;
        //     regs.insert(pair<string, int>(it.second.msg, reg_index));
        //     reg_index++;
        // }
    }
    // string toMIPS(string op, int t = -1, int r1 = -1, int r2 = -1) // r2���Ա�ʾ�����Ĵ�������Ŀ���ַ
    // {
    //     string MIPS;
    //     if (op == "+" || op == "-" || op == "*" || op == "/" ||)
    //     {
    //         MIPS = op + " $REG" + to_string(t);
    //         if (r1 != -1)
    //         {
    //             MIPS += " $REG" + to_string(r1);
    //         }
    //     }
    // }
    // void translateMIPS(ASTNode *root)
    // {
    //     if (root->children[0]->token == "id")
    //     {
    //         if (token_map[root->children[0]->label].type == INTEGER)
    //         {
    //         }
    //     }
    // }
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

    LexAnalysis la("caltest.c");
    la.analysis();
    la.showResult();
    map<string, node> tm = la.token_map;
    vector<node> e = la.elements;
    node n("$");
    e.push_back(n);
    LL1 l(e, tm);
}