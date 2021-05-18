//
// Created by Ricky on 2021/4/9.
//
#include <bits/stdc++.h>
#include "tokens.h"
#include "node.h"

using namespace std;

class LexAnalysis
{
private:
    ifstream f_input;
    ostringstream s_input;
    string codes;
    int cur_line;
    //    set<string> keywords{"const", "int", "double", "char", "string", "hex", "funct", "return", "if", "else", "for",
    //                         "while"};   // 关键字集合
    map<string, int> keywords;
    map<string, node> token_map; // 符号表
    vector<node> elements;

public:
    LexAnalysis(const char *file) : f_input(file)
    {
        initMap();
        cur_line = 1;
        s_input << f_input.rdbuf();
        codes = s_input.str();
        cout << codes << endl;
        f_input.close();
        f_input.clear();
    }

    void initMap()
    {
        keywords["const"] = CONST;
        keywords["int"] = INTEGER;
        keywords["double"] = DOUBLE;
        keywords["char"] = CHAR;
        keywords["string"] = STRING;
        keywords["hexint"] = HEXINT;
        keywords["hexdou"] = HEXDOU;
        keywords["funct"] = FUNCT;
        keywords["return"] = RETURN;
        keywords["if"] = IF;
        keywords["else"] = ELSE;
        keywords["for"] = FOR;
        keywords["while"] = WHILE;
        // for operators
        keywords["+"] = ADD;
        keywords["-"] = SUB;
        keywords["*"] = MUL;
        keywords["/"] = DIV;
        keywords["="] = EQUAL;
        keywords["=="] = CEQ;
        keywords["!="] = CNE;
        keywords["<"] = CLT;
        keywords["<="] = CLE;
        keywords[">"] = CGT;
        keywords[">="] = CGE;
        //        keywords["."]=;
    }

    void analysis()
    {
        int index = 0; // position of current char
        int len = codes.length();
        while (index < len)
        {
            char temp = codes[index];
            //            cout << index << ' ' << (int) temp << endl;
            string op(1, temp);
            if (temp == ' ')
            {
                index++;
                continue;
            }
            else if (temp == '\r')
            {
                index += 2;
                cur_line++;
                continue;
            }
            // 若为字母或下划线则按变量和关键字进行匹配
            else if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || temp == '_')
            {
                string str = "";
                while (index < len)
                {
                    temp = codes[index];
                    if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9') ||
                        temp == '_')
                    {
                        str += temp;
                    }
                    else
                    {
                        break;
                    }
                    index++;
                }
                if (keywords.find(str) != keywords.end())
                { // 若为关键字
                    node k(keywords[str], cur_line, str);
                    elements.push_back(k);
                }
                else
                { // 若非关键字则为标识符
                    node i(IDENTIFIER, cur_line, str);
                    elements.push_back(i);
                    if (token_map.find(str) != token_map.end())
                    { // 若符号表已有标识符
                        token_map.at(str).lines.push_back(cur_line);
                    }
                    else
                    {
                        token_map.insert(pair<string, node>(str, i));
                    }
                }
                continue;
            }
            // 若为数字开头则只能为int或double或hex(0xfffffff)
            else if (temp >= '0' && temp <= '9')
            {
                string str = "";
                int flag = 0; // 0=int, 1=hexint, 2=double, 3=hexdou, -1=error
                if (index + 1 < len)
                {
                    if (codes[index] == '0')
                    {
                        if (codes[index + 1] == 'x')
                        { // 符合hex规则
                            flag = 1;
                            str.append("0x");
                            index += 2;
                        }
                    }
                }
                while (index < len)
                {
                    temp = codes[index];
                    if ((temp >= 'a' && temp <= 'f' && flag == 1) || (temp >= '0' && temp <= '9'))
                    {
                        str += temp;
                    }
                    else if (temp == '.')
                    {
                        if (flag == 0)
                        {
                            str += temp;
                            flag = 2;
                        }
                        else if (flag == 1)
                        {
                            str += temp;
                            flag = 3;
                        }
                        else if (flag == 2 || flag == 3)
                        { // 两次出现浮点号说明浮点错误
                            flag = DOUBLE_ERROR;
                            break;
                        }
                    }
                    else if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z'))
                    {
                        cout << "new " << temp;
                        flag = NAME_ERROR; // 数字后面出现非法符号表示命名错误
                        str = LEX_ERROR + str;
                        break;
                    }
                    else
                    {
                        break;
                    }
                    index++;
                }
                int v = flag == 0 ? INTEGER : flag == 1 ? HEXINT
                                          : flag == 2   ? DOUBLE
                                          : flag == 3   ? HEXDOU
                                                        : flag;
                node c(v, cur_line, str);
                //                c.save_token(0,op);
                elements.push_back(c);
                continue;
            }
            // 若为操作符
            else if (keywords.find(op) != keywords.end())
            {
                cout << "match operators" << endl;
                if ((temp != '=' && temp != '<' && temp != '>' && temp != '!') || index + 1 >= len)
                {
                    node o(keywords[op], cur_line, op);
                    //                    o.save_token(0,op);
                    elements.push_back(o);
                }
                else
                {
                    string str = op + codes[index + 1]; // 两位操作符
                    if (keywords.find(str) != keywords.end())
                    {
                        node o(keywords[str], cur_line, str);
                        //                        o.save_token(0,str);
                        elements.push_back(o);
                        index++;
                    }
                    else
                    {
                        node o(keywords[op], cur_line, op);
                        //                        o.save_token(0,op);
                        elements.push_back(o);
                    }
                }
            }
            // 若为定界符
            else if (temp == '(')
            {
                node d(LPAREN, cur_line, "(");
                //                d.save_token(0,"(");
                elements.push_back(d);
            }
            else if (temp == ')')
            {
                node d(RPAREN, cur_line, ")");
                //                d.save_token(0,")");
                elements.push_back(d);
            }
            else if (temp == '{')
            {
                node d(LBRACE, cur_line, "{");
                //                d.save_token(0,"{");
                elements.push_back(d);
            }
            else if (temp == '}')
            {
                node d(RBRACE, cur_line, "}");
                //                d.save_token(0,"}");
                elements.push_back(d);
            }
            else if (temp == '[')
            {
                node d(LBRACK, cur_line, "[");
                //                d.save_token(0,"[");
                elements.push_back(d);
            }
            else if (temp == ']')
            {
                node d(RBRACK, cur_line, "]");
                //                d.save_token(0,"]");
                elements.push_back(d);
            }
            // 若为分隔符
            else if (temp == ',')
            {
                node s(COMMA, cur_line, ",");
                //                s.save_token(0,",");
                elements.push_back(s);
            }
            else if (temp == ':')
            {
                node s(COLON, cur_line, ":");
                //                s.save_token(0,":");
                elements.push_back(s);
            }
            else if (temp == ';')
            {
                node s(SEMICOLON, cur_line, ";");
                //                s.save_token(0,";");
                elements.push_back(s);
            }
            // 非法符号
            else
            {
                node e(TOKEN_ERROR, cur_line, LEX_ERROR);
                elements.push_back(e);
            }
            index++;
        }
    }

    void showResult()
    {
        cout << "--------------------------------------------------" << endl;
        cout << "               LEX ANALYSIS RESULT" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << setiosflags(ios::left) << setw(10) << "line" << setw(30) << "word" << resetiosflags(ios::left)
             << setiosflags(ios::right) << setw(10) << "type" << resetiosflags(ios::right) << endl;
        cout << "--------------------------------------------------" << endl;
        for (int i = 0; i < elements.size(); i++)
        {
            cout << setiosflags(ios::left) << setw(10) << elements[i].line << setw(30) << elements[i].msg
                 << resetiosflags(ios::left) << setiosflags(ios::right) << setw(10) << elements[i].value
                 << resetiosflags(ios::right) << endl;
        }
        cout << "--------------------------------------------------" << endl;
        cout << endl
             << "--------------------------------------------------" << endl;
        cout << "                   TOKENS TABLE" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << setiosflags(ios::left) << setw(10) << "name" << setw(10) << "declare" << resetiosflags(ios::left)
             << setw(30) << "calls" << endl;
        cout << "--------------------------------------------------" << endl;
        for (map<string, node>::iterator i = token_map.begin(); i != token_map.end(); i++)
        {
            string temp = "";
            for (int j = 0; j < i->second.lines.size(); j++)
            {
                temp += to_string(i->second.lines[j]) + " ";
            }
            cout << setiosflags(ios::left) << setw(10) << i->first << setw(10) << i->second.line
                 << resetiosflags(ios::left) << setw(30) << temp << endl;
        }
    }
};

int main()
{
    char *file = "test.c";
    LexAnalysis la(file);
    la.analysis();
    la.showResult();
}