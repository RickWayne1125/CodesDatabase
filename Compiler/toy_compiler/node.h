#include <bits/stdc++.h>
#include "tokens.h"

using namespace std;

class node
{
private:
    string str_val;
    int int_val;
    double dou_val;
    char char_val;

public:
    // save info
    int value;         // identified value in tokens.h
    int line;          // line position of declaration
    string msg;        // true value in string
    vector<int> lines; // lines exist the token
    string terminal;   // terminal symbol
    node(int v = IDENTIFIER, int l = 1, string m = LEX_ERROR)
    {
        value = v;
        line = l;
        vector<int> lines; // 出现过的行
        msg = m;
        terminal = (v == IDENTIFIER) ? "id" : (v == INTEGER) ? "num"
                                          : (v == TYPE)      ? "type"
                                                             : m;
    }
    node(string t)
    {
        terminal = t;
    }

    void save_token(int i = 0, string s = "", double d = 0.0, char c = ' ')
    {
        if (value == INTEGER)
        {
            int_val = i;
        }
        else if (value == DOUBLE)
        {
            dou_val = d;
        }
        else if (value == CHAR)
        {
            char_val = c;
        }
        else
        {
            str_val = s;
        }
    }

    string get_token()
    {
        if (value == INTEGER)
        {
            return to_string(int_val);
        }
        else if (value == DOUBLE)
        {
            return to_string(dou_val);
        }
        else if (value == CHAR)
        {
            return to_string(char_val);
        }
        else
        {
            return str_val;
        }
    }
};