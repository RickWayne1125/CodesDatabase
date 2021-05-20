#include <bits/stdc++.h>

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
