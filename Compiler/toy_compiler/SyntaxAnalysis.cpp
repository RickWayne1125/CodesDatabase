#include <bits/stdc++.h>
#include "LexAnalysis.cpp"
#include "tokens.h"
// #include "node.h"
// #include "productions.h"
#include "utils.h"

using namespace std;

class AST
{
private:
    string text; // 当前串
public:
    vector<AST *> children; // 子节点
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
    stack<string> ana_stack;   // 分析栈
    vector<string> buffer;     // 输入缓冲区
    vector<string> error_list; // 出现错误的输入串中的符号

public:
    LL1(vector<string> tl, vector<node> e)
    {
        token_list = tl;
        elements = e;
        initProduction();
        getFIRSTset();
        getFOLLOWset();
        getPredictTable();
        show();
        analysis();
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
            string a = e.terminal;      // 输入符号a
            string x = ana_stack.top(); // 栈顶符号x
            cout << "x: " << x << ", a: " << a << endl;
            try
            {
                if (isTERMINAL(x))
                {
                    if (x == a)
                    {
                        ana_stack.pop();
                        continue;
                    }
                    else
                    {
                        // throw("GrammerError");
                    }
                }
                else if (isNON_TERMINAL(x))
                {
                    production p = pre_table[x][a];
                    p.show();
                    if (p.str != "")
                    {
                        ana_stack.pop();
                        for (auto iter = p.right.rbegin(); iter != p.right.rend(); iter++)
                        {
                            ana_stack.push(*iter);
                        }
                    }
                    else
                    {
                        // throw("MatchError");
                    }
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
                error_list.push_back(a);
                continue;
            }
            if (ana_stack.empty())
            {
                cout << "Syntax Analysis Succeed!" << endl;
            }
        }
    }
    void insertPredictTable(string n, string t, production p)
    {
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
                        insertPredictTable(p.left, p.right[0], p);
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
        for (int i = 0; i < col; i++)
        {
            max.push_back(13);
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
    }
};

int main()
{
    LexAnalysis la("syn_test.c");
    la.analysis();
    la.showResult();
    vector<string> tl;
    vector<node> e = la.elements;
    LL1 l(tl, e);
}