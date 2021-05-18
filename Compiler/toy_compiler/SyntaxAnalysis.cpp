#include <bits/stdc++.h>
#include "tokens.h"
#include "node.h"

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
    // map<>
public:
    LL1(vector<string> tl, vector<node> e)
    {
        token_list = tl;
        elements = e;
    }

};