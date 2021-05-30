//
// Created by Ricky on 5/18/2021.
//
#include <bits/stdc++.h>
// 终结符表与非终结符表
set<string> NON_TERMINAL_LIST{"S",
                              //"E", "T", "T1", "F",
                              "A", "B", "B'", "S'"};
set<string> TERMINAL_LIST = {"none", "$",   
                             "if", "id", "num","type",
                             "=", "-", "+", "*", "/",  "(", ")", ";"};

// 产生式编码
#define TEST1 "S -> T E"
#define TEST2 "E -> + T E"
#define TEST3 "E -> none"
#define TEST4 "T -> F T1"
#define TEST5 "T1 -> * F T1"
#define TEST6 "T1 -> none"
#define TEST7 "F -> ( S )"
#define TEST8 "F -> id"

#define PRO_DECLARE_INT "S -> type A"
#define PRO_EQUAL "S -> A = B"
#define PRO_ADD "B -> id B'"
#define PRO_IDEN_A "A -> id"
#define PRO_IDEN_B "B' -> id"

// 产生式列表
vector<string> productions = {
    // TEST1,
    // TEST2,
    // TEST3,
    // TEST4,
    // TEST5,
    // TEST6,
    // TEST7,
    // TEST8,
    // PRO_DECLARE_INT,
    // PRO_ADD,
    // PRO_A_END,
    "S -> S' S",
    "S -> none",
    "S' -> type A ;",
    "A -> id",
    "S' -> A = B ;",
    "B -> id B'",
    "B -> num B'",
    "B' -> none",
    "B' -> + B B'"};

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
    string str;
    production()
    {
        left = "";
        str = "";
    }
    production(string pro)
    {
        vector<string> sp_r = split(pro, " ");
        left = sp_r[0];
        str = left + " ->";
        for (int i = 2; i < sp_r.size(); i++)
        {
            right.push_back(sp_r[i]);
            str += " " + sp_r[i];
        }
    }

    void show()
    {
        std::cout << "Production: ";
        std::cout << str;
        // std::cout << left << " -> ";
        // for (int i = 0; i < right.size(); i++)
        // {
        //     std::cout << right[i] << ' ';
        // }
        std::cout << endl;
    }
};
