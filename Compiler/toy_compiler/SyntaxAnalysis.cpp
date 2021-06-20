#include <bits/stdc++.h>
#include "LexAnalysis.cpp"
#include "tokens.h"
// #include "node.h"
// #include "productions.h"
#include "utils.h"

using namespace std;

struct SynError
{
    int line;    // 错误所在行数
    string type; // 错误类型
    string x;    // 错误栈顶符号
    string a;    // 错误输入符号
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
    // ASTNode *next_sibling;      // 下一个兄弟节点
    int code;                   // 每个节点的唯一标识符
    vector<ASTNode *> children; // 子节点
    string label;               // 对应终结符/非终结符
    // 语法制导翻译所需属性
    string token;  // 为终结符时的标志，同时也可以作为符号表入口指向token map中的位置
    int type;      // 该节点所表示的类型
    int int_val;   // 该节点的整型值
    bool bool_val; // 该节点的布尔值
    int line;      // 该节点所在行数
    int reg;       // 对应的临时寄存器编号

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
    stack<string> ana_stack;     // 分析栈
    vector<string> buffer;       // 输入缓冲区
    vector<SynError> error_list; // 出现错误的输入串中的符号
    ASTNode *root;               // 语法分析树根节点
    AST tree;                    // 语法分析树
    vector<production> history;  // 产生式使用记录
    int index;                   // 产生式使用历史下标
    int code;                    // 当前节点编码
    // 语法制导翻译所需属性
    vector<string> terminal_history; // 终结符匹配历史
    int index2;                      // 终结符下标
    // 目标代码生成所需属性
    int reg_index;         // 当前最大寄存器编号
    vector<string> mips;   // MIPS指令
    map<string, int> regs; // 寄存器组映射表，key为常量/标识符，value为寄存器编号
    int last_address;      // 最近一次操作的地址（用于goto）

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
            string cur_symbol = pro[i].right[0]; // 产生式右侧第一个符号
            // 若该符号为终结符
            if (isTERMINAL(cur_symbol))
            {
                first_map[left].insert(cur_symbol);
            }
            else if (isNON_TERMINAL(cur_symbol))
            {
                insertFIRST(left, cur_symbol);
                for (size_t j = 0; j < pro[i].right.size(); j++)
                {
                    // 当前符号可以指向空时
                    // Y1...Yj-1 -> none 则 FIRST(Yj)加入FIRST(X)
                    int flag = 0;                           // 表示当前符号是否可以指向none
                    for (auto iter : pros[pro[i].right[j]]) // production iter
                    {
                        if (iter.right[0] == "none")
                        {
                            if (j != pro[i].right.size() - 1)
                                insertFIRST(left, pro[i].right[j + 1]);
                            else // 对于产生式文末符号
                            {
                                first_map[left].insert("none"); // 将none加入FIRST(X)
                            }
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0)
                    {
                        break; // 若当前符号不可指向none则不再继续判断
                    }
                }
            }
        }
    }

    void insertFOLLOWbyFIRST(string b, string a)
    {
        // cout << "insert first of " << a << " to " << b << endl;
        // 将FIRST(a)-none放入FOLLOW(b)
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
        // 将FOLLOW(a)放入FOLLOW(b)
        for (auto iter : follow_map[a])
        {
            follow_map[b].insert(iter);
        }
    }

    void getFOLLOW(production p)
    {
        int flag = 0; // 表示后继符号是否可以指向空
        for (int i = p.right.size() - 1; i >= 0; i--)
        {
            string cur_symbol = p.right[i];
            if (isNON_TERMINAL(cur_symbol))
            {
                // 当上一个符号可以指向空时，将FOLLOW(A)放入FOLLOW(B)
                if (flag == 1)
                {
                    insertFOLLOWbyFOLLOW(cur_symbol, p.left);
                }
                flag = 0;
                // 对于产生式最后一个非终结符B，将FOLLOW(A)放入FOLLOW(B)
                if (i == p.right.size() - 1)
                {
                    insertFOLLOWbyFOLLOW(cur_symbol, p.left);
                }
                // 对于A->aBb的产生式，将FIRST(b)-none加入FOLLOW(B)
                else
                {
                    insertFOLLOWbyFIRST(cur_symbol, p.right[i + 1]);
                }
                // 判断当前符号是否可以指向空
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
                // 终结符不能指向空
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
            { // map中已经存有key的情况
                pros[p.left].push_back(p);
            }
            else
            { // map中不存在key的情况
                vector<production> temp;
                temp.push_back(p);
                pros.insert(pair<string, vector<production>>(p.left, temp));
            }
        }
    }

    void getFIRSTset() // 生成FIRST集的map
    {
        // 生成非终结符在first_map中的对应位置
        for (auto iter : NON_TERMINAL_LIST)
        {
            string left = iter;
            set<string> temp;
            first_map.insert(pair<string, set<string>>(left, temp));
        }
        // 生成终结符的FIRST集
        for (auto iter : TERMINAL_LIST)
        {
            string left = iter;
            set<string> temp;
            temp.insert(left);
            first_map.insert(pair<string, set<string>>(left, temp));
        }
        // 生成FIRST集
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
        // 生成非终结符在follow_map中对应的位置
        for (auto iter : NON_TERMINAL_LIST)
        {
            set<string> temp;
            if (iter == "S")
                temp.insert("$");
            follow_map.insert(pair<string, set<string>>(iter, temp));
        }
        map<string, set<string>> comp;
        // 遍历产生式，求FOLLOW集，直到集合不再变化
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

    bool check() // 检查是否符合文法规则
    {
        // 是否不含左递归
        for (auto iter : pros)
        {
            for (auto p : iter.second)
            {
                if (p.left == p.right[0])
                    return false;
            }
        }
        // 终结符集是否两两不相交
    }

    void analysis()
    {
        cout << "Syntax Analysis Start!" << endl;
        ana_stack.push("S");
        for (auto e : elements)
        {
            while (!ana_stack.empty())
            {
                string a = e.terminal; // 输入符号a
                string t = e.msg;      // 对应的实际符号
                cout << e.line << endl;
                while (!ana_stack.empty() && ana_stack.top() == "none")
                {
                    cout << "Replace None" << endl;
                    ana_stack.pop();
                }
                if (ana_stack.empty())
                    break;
                string x = ana_stack.top(); // 栈顶符号x
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
        // 初始化预测分析表
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
        // 构建预测分析表
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
                        // 遍历左部FOLLOW集
                        for (auto follow : follow_map[p.left])
                        {
                            insertPredictTable(p.left, follow, p);
                        }
                    }
                }
                else if (isNON_TERMINAL(p.right[0]))
                {
                    // 遍历首部非终结符FIRST集
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
        getTarget();                   // 首先将变量和常量的寄存器分配好
        int address = mips.size() - 1; // 当前指令的地址
        // 先遍历计算每个子结点的属性，同时确认闭包是否完备
        int cnt1 = 0; // {}是否完备，为0表示完备
        int cnt2 = 0; // ()是否完备，为0表示完备
        int cnt3 = 0; // []是否完备，为0表示完备
        // 给当前节点分配临时寄存器
        if (root->token == "id")
        {
            root->reg = token_map[root->label].reg;
        }
        else
        {
            root->reg = reg_index;
            reg_index++;
        }
        // 首先计算继承属性
        int type;
        for (auto it : root->children)
        {
            // 当出现声明语句时
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
                    // 如果右侧为变量则查填符号表
                    if (token_map[it->token].type < 0) // 默认构造时的node->type小于0，因此type大于0则出现了重声明
                    {
                        token_map[it->token].type = type;
                    }
                    else // 变量重复声明
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
        // 接下来计算综合属性
        // 当出现赋值语句的时候
        else if (p.str == PRO_EQUAL)
        {
            string MIPS = "LI reg" + to_string(root->children[0]->reg) + ", reg" + to_string(root->children[1]->reg);
            mips.push_back(MIPS);
        }
        // 当出现A->id时
        else if (p.str == PRO_ID_A)
        {
            string MIPS = "MOVE reg" + to_string(token_map[root->children[0]->label].reg) + ", reg" + to_string(root->reg);
            mips.push_back(MIPS);
        }
        // 当出现一般计算语句时
        else if (p.str == PRO_EXP_ID || p.str == PRO_EXP_NUM)
        {
            // 检查两侧的类型
            // 若不一致则输出错误信息
            if (p.right[0] == "id" || p.right[0] == "num")
            {
                if (root->children[0]->type != root->children[1]->type && root->children[1]->type >= 0 && root->children[0]->type >= 0)
                {
                    cout << "Cannot operate variables of different types! Error between " << root->children[0]->token << " and " << root->children[1]->label << " at line: " << root->children[0]->line << endl;
                }
            }
            // 对父节点的类型进行更新
            root->type = root->children[0]->type;
            string MIPS = "MOVE reg" + to_string(root->reg) + ", reg" + to_string(root->children[0]->reg);
            mips.push_back(MIPS);
        }
        // 当出现计算闭包时
        else if (p.left == "B'")
        {
            root->type = (root->children.size() == 1) ?: root->children[1]->type;
            if (root->children.size() == 1)
            {
                // 若右侧只有运算符，则报错：丢失操作数
                if (root->children[0]->label == "+" || root->children[0]->label == "-" || root->children[0]->label == "*" || root->children[0]->label == "/" || root->children[0]->label == "|" || root->children[0]->label == "&")
                {
                    cout << "Missing Operate Number at line: " << root->line << endl;
                }
                // 若右侧只有标识符，则报错：丢失运算符
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
        // 当产生式指向单独的标识符或常量时
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
            translate(root->children[2]); // 翻译条件块
            translate(root->children[5]); // 翻译执行块
            mips.push_back(go_back);
        }
        else if (p.str == PRO_EXP_IF || p.str == PRO_EXP_IF_ELSE)
        {
            last_address = address + 2;
            int label = address;
            mips.push_back(to_string(label) + ":");
            translate(root->children[2]); // 翻译条件块
            translate(root->children[5]); // 翻译执行块
        }
        else if (p.str == PRO_GET || p.str == PRO_PUT)
        {
            string MIPS = "SYSCALL";
            mips.push_back(MIPS);
        }
        // 回收临时变量寄存器
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
        // 生成子结点
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
        // 输出预测分析表
        // 列数&行数
        int row = NON_TERMINAL_LIST.size();
        int col = TERMINAL_LIST.size() + 1;
        // 构造表头
        vector<string> D;
        D.push_back(" ");
        for (auto iter : TERMINAL_LIST)
        {
            D.push_back(iter);
        }
        // 构造列头
        vector<string> R;
        for (auto iter : NON_TERMINAL_LIST)
        {
            R.push_back(iter);
        }
        // 构造最大列宽
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
        // 构造表数据
        vector<vector<string>> Str;
        for (int i = 0; i < row; i++)
        {
            vector<string> temp;
            string n = R[i]; // 非终结符
            temp.push_back(n);
            for (int j = 1; j < col; j++)
            {
                string t = D[j]; // 终结符
                temp.push_back(pre_table[n][t].str);
            }
            Str.push_back(temp);
        }
        // 绘制预测分析表
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
        // 首先为常量分配寄存器
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
        // 之后为声明的变量分配寄存器
        // for (auto it : token_map)
        // {
        //     it.second.reg = reg_index;
        //     regs.insert(pair<string, int>(it.second.msg, reg_index));
        //     reg_index++;
        // }
    }
    // string toMIPS(string op, int t = -1, int r1 = -1, int r2 = -1) // r2可以表示操作寄存器或者目标地址
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