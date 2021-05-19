#include <bits/stdc++.h>
#include "tokens.h"
#include "node.h"
#include "productions.h"

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
    stack<node> ana_stack;
    map<string, set<string>> first_map;
    map<string, set<string>> follow_map;
    map<string, vector<production>> pros; // map<non terminal symbol on the left, production>
public:
    LL1(vector<string> tl, vector<node> e)
    {
        token_list = tl;
        elements = e;
        initProduction;
    }

    void insertFIRST(string left, string cur_symbol)
    {
        if (first_map[cur_symbol].size() == 0)
        {
            getFIRST(cur_symbol);
        }
        for (auto iter : first_map[cur_symbol])
        {
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
            if (TERMINAL_LIST.find(cur_symbol) != TERMINAL_LIST.end())
            {
                first_map[left].insert(cur_symbol);
            }
            else if (NON_TERMINAL_LIST.find(cur_symbol) != NON_TERMINAL_LIST.end())
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

    void getFIRSTset()
    {
        for (auto iter : pros)
        {
        }
    }
};

int main()
{
    production p(DECLARE_INT);
    p.show();
}