//
// Created by Ricky on 5/18/2021.
//
#include <bits/stdc++.h>
// 终结符表与非终结符表
set<string> NON_TERMINAL_LIST{"S", "A", "B", "C"};
set<string> TERMINAL_LIST = {"none", "if", "+", "id", "-", "*", "/", "int"};

// 产生式编码
#define PRO_DECLARE_INT "S -> int A"
#define PRO_ADD "S -> A + A"
#define PRO_A_END "A -> none"

// 产生式列表
vector<string> productions = {
    PRO_DECLARE_INT,
    PRO_ADD,
    PRO_A_END
};

// 分割函数
vector<string> split(const string &str, const string &delim)
{
    vector<string> res;
    if ("" == str)
        return res;
    char *strs = new char[str.length() + 1];
    strcpy(strs, str.c_str());
    char *d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());
    char *p = strtok(strs, d);
    while (p)
    {
        string s = p;
        res.push_back(s);
        p = strtok(NULL, d);
    }
    return res;
}

// 产生式类型
struct production
{
    string left;          // 产生式左侧
    vector<string> right; // 产生式右侧
    production(string pro)
    {
        vector<string> sp_r = split(pro, " ");
        left = sp_r[0];
        for (int i = 2; i < sp_r.size(); i++)
        {
            right.push_back(sp_r[i]);
        }
    }

    void show()
    {
        std::cout << "Production: ";
        std::cout << left << " -> ";
        for (int i = 0; i < right.size(); i++)
        {
            std::cout << right[i] << ' ';
        }
        std::cout << endl;
    }
};
