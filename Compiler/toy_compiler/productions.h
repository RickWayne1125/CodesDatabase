//
// Created by Ricky on 5/18/2021.
//
#include <bits/stdc++.h>
// 终结符表与非终结符表
set<string> NON_TERMINAL_LIST{
    "S", // 分析开始标识
    //"E", "T", "T1", "F",
    "BLOCK",     // 语句块开始标识
    "S'",        // 单条语句开始标识
    "LOGIC",     // 逻辑表达式
    "ELSE",      // else起始标志
    "FOR",       // for循环起始标志
    "ID", "ID'", // 标识符序列
    "A",         // 变量
    "B",         // 变量/表达式/数字常量
    "B'",        // 用于消除B左递归
    "DEC",
    "FUNCT",
    "PARAM"};
set<string> TERMINAL_LIST = {
    // 空与结束符号
    "none", "$",
    // 关键字
    "if", "else", "type", "get", "put", "while", "for", "return",
    // 变量与常量
    "id", "num", "string", "char",
    // 运算符
    "=", "-", "+", "*", "/", "&", "|",
    // 逻辑运算符
    "<", ">", "==", "!=", "<=", ">=", "&&", "||",
    // 分割符
    "(", ")", "{", "}", ";", ",", "[", "]"};

// 产生式编码
#define TEST1 "S -> T E"
#define TEST2 "E -> + T E"
#define TEST3 "E -> none"
#define TEST4 "T -> F T1"
#define TEST5 "T1 -> * F T1"
#define TEST6 "T1 -> none"
#define TEST7 "F -> ( S )"
#define TEST8 "F -> id"

#define PRO_BEGIN "S -> BLOCK"
#define PRO_BLOCK "BLOCK -> S' BLOCK"
#define PRO_NONE_BLOCK "BLOCK -> none"
// #define PRO_END "S -> none"
#define PRO_DECLARE "S' -> type ID DEC"
#define PRO_DEC_IDENT "DEC -> ;"
#define PRO_DEC_FUNCT "DEC -> ( PARAM ) { BLOCK } ;"
// #define PRO_FUNCT "FUNCT -> ( PARAM ) { BLOCK }"
#define PRO_PARAM "PARAM -> type A PARAM"
#define PRO_PARAM_SPLIT "PARAM -> , PARAM"
#define PRO_PARAM_NONE "PARAM -> none"
// #define PRO_EXP_FUNCT "S' -> id ( PARAM ) ;"
#define PRO_EXP_RETURN "S' -> return B ;"

#define PRO_GET "S' -> get ( ID ) ;"
#define PRO_PUT "S' -> put ( ID ) ;"
#define PRO_ID_ID "ID -> A ID'"
#define PRO_ID_LIST "ID' -> , ID"
#define PRO_NONE_ID "ID' -> none"
#define PRO_EQUAL "S' -> A = B ;"
#define PRO_EXP_ID "B -> id B' FUNCT"
#define PRO_FUNCT_PARAM "FUNCT -> ( PARAM )"
#define PRO_FUNCT_NONE "FUNCT -> none"
#define PRO_EXP_NUM "B -> num B'"
#define PRO_EXP_CLO "B -> ( B )" // 表达式闭包
#define PRO_EXP_ADD "B' -> + B B'"
#define PRO_EXP_SUB "B' -> - B B'"
#define PRO_EXP_MUL "B' -> * B B'"
#define PRO_EXP_DIV "B' -> / B B'"
#define PRO_EXP_AND "B' -> & B B'"
#define PRO_EXP_OR "B' -> | B B'"
#define PRO_EXP_EQU "B' -> == B B'"
#define PRO_EXP_UEQ "B' -> != B B'"
#define PRO_EXP_BEQ "B' -> >= B B'"
#define PRO_EXP_LEQ "B' -> <= B B'"
#define PRO_EXP_BNE "B' -> > B B'"
#define PRO_EXP_LNE "B' -> < B B'"
#define PRO_EXP_PARAM "B' -> ( ID )"
#define PRO_NONE_B "B' -> none"
#define PRO_ID_A "A -> id"

#define PRO_EXP_IF "S' -> if ( LOGIC ) { BLOCK } ; ELSE"
#define PRO_EXP_WHILE "S' -> while ( LOGIC ) { BLOCK } ;"
#define PRO_EXP_FOR "S' -> for ( LOGIC ; B ) { BLOCK } ;"
#define PRO_EXP_ELSE "ELSE -> else { BLOCK } ;"
#define PRO_EXP_IF_ELSE "ELSE -> else if ( LOGIC ) { BLOCK } ;"
#define PRO_NONE_ELSE "ELSE -> none"
#define PRO_LOGIC "LOGIC -> B"
// 产生式列表
vector<string>
    productions = {
        PRO_BEGIN,
        PRO_BLOCK,
        PRO_DECLARE,
        PRO_DEC_FUNCT,
        PRO_DEC_IDENT,
        PRO_PARAM,
        PRO_PARAM_SPLIT,
        PRO_PARAM_NONE,
        PRO_EQUAL,
        PRO_EXP_ADD,
        PRO_EXP_AND,
        PRO_EXP_BEQ,
        PRO_EXP_BNE,
        PRO_EXP_CLO,
        PRO_EXP_DIV,
        PRO_EXP_ELSE,
        PRO_EXP_EQU,
        // PRO_EXP_FUNCT,
        PRO_EXP_ID,
        PRO_EXP_IF,
        PRO_EXP_LEQ,
        PRO_EXP_LNE,
        PRO_EXP_MUL,
        PRO_EXP_NUM,
        PRO_EXP_OR,
        PRO_EXP_SUB,
        PRO_EXP_UEQ,
        PRO_EXP_WHILE,
        PRO_ID_A,
        PRO_ID_ID,
        PRO_ID_LIST,
        PRO_LOGIC,
        PRO_NONE_B,
        PRO_NONE_BLOCK,
        PRO_NONE_ELSE,
        PRO_NONE_ID,
        PRO_GET, PRO_PUT,
        PRO_EXP_RETURN, 
        // PRO_EXP_PARAM,
        PRO_FUNCT_NONE,PRO_FUNCT_PARAM,
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
        // "S -> S' S",
        // "S -> none",
        // "S' -> type A ;",
        // "A -> id",
        // "S' -> A = B ;",
        // "B -> id B'",
        // "B -> num B'",
        // "B' -> none",
        // "B' -> + B B'"
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
        std::cout << endl;
    }
};
