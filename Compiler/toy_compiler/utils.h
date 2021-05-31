#include <bits/stdc++.h>
#include "productions.h"

bool isTERMINAL(string cur_symbol)
{
    return TERMINAL_LIST.find(cur_symbol) != TERMINAL_LIST.end();
}

bool isNON_TERMINAL(string cur_symbol)
{
    return NON_TERMINAL_LIST.find(cur_symbol) != NON_TERMINAL_LIST.end();
}

template <typename K, typename V>
bool CompareMap(const std::map<K, V> &map1, const std::map<K, V> &map2)
{
    if (map1.size() != map2.size())
    {
        return false;
    }
    for (auto it1 : map1)
    {
        auto it2 = map2.find(it1.first);
        if (it2 == map2.end())
        {
            return false;
        }
        else
        {
            // if (0 != memcmp(&it1.second, &it2->second, sizeof(V)))
            // {
            //     return false;
            // }
            if (it1.second.size() != it2->second.size())
            {
                return false;
            }
        }
    }
    return true;
}

void Draw_line(vector<int> max, int columns)
{ //画行线
    for (int i = 0; i < columns; i++)
    {
        cout << "+-";
        for (int j = 0; j <= max[i]; j++)
        {
            cout << '-';
        }
    }
    cout << '+' << endl;
}

void Draw_Datas(vector<int> max, vector<vector<string>> Str, vector<string> D, int columns, int row)
{ //显示构造过程，状态转换矩阵
    Draw_line(max, columns);
    for (int i = 0; i < D.size(); i++)
    {
        cout << "| " << setw(max[i]) << setiosflags(ios::left) << setfill(' ') << D[i] << ' ';
    }
    cout << '|' << endl;
    Draw_line(max, columns);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "| " << setw(max[j]) << setiosflags(ios::left) << setfill(' ');
            cout << Str[i][j] << ' ';
        }
        cout << '|' << endl;
    }
    Draw_line(max, columns);
}

