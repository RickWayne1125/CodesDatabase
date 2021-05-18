#include <bits/stdc++.h>
#include "tokens.h"
#include "node.h"
#include "productions.h"

using namespace std;


class AST {
private:
    string text; // 当前串
public:
    vector<AST *> children; // 子节点
};

class LL1 {
private:
    vector<string> token_list;
    vector<node> elements;
    stack<node> ana_stack;
    map<string, set<string>> first_map;
    map<string, set<string>> follow_map;
    map<string, vector<production>> pros;   // map<non terminal symbol on the left, production>
public:
    LL1(vector<string> tl, vector<node> e) {
        token_list = tl;
        elements = e;
    }


    void getFIRST(string left) {
        vector<production> pro = pros[left];
        for (int i = 0; i < pro.size(); ++i) {
            string cur_symbol = pro[i].right[0];    // 产生式右侧第一个符号
            // 若该符号为终结符
            if (TERMINAL_LIST.find(cur_symbol) != TERMINAL_LIST.end()) {
                first_map[left].insert(cur_symbol);
            } else if (NON_TERMINAL_LIST.find(cur_symbol) != NON_TERMINAL_LIST.end()) {
//                while(pros[cur_symbol])
                if (first_map[cur_symbol].size() != 0) {
                    for (auto iter:first_map[cur_symbol]) {
                        first_map[left].insert(iter);
                    }
                } else {
                    getFIRST(cur_symbol);
                }
            }
        }
//        for (auto iter:pros) {
//            for (int i = 0; i < iter.second.size(); i++) {
//                // 产生式右侧第一个符号为终结符时
//                if (TERMINAL_LIST.find(iter.second[i].right[0]) != TERMINAL_LIST.end()) {
//                    first += iter.second[i].right[0];
//                } else if (NON_TERMINAL_LIST.find(iter.second[i].right[0]) != NON_TERMINAL_LIST.end()) {
//
//                }
//            }
//        }
    }
};

int main() {
    production p(DECLARE_INT);
    p.show();
}