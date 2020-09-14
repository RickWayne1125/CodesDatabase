class Solution {
public:
    void reOrderArray(vector<int>& array) {
        vector<int> ans1;
        vector<int> ans2;
        for (int i = 0; i < array.size(); i++) {
            if (array[i] % 2 == 1)   ans1.push_back(array[i]);
            else ans2.push_back(array[i]);
        }
        ans1.insert(ans1.end(), ans2.begin(), ans2.end());
        array = ans1;
    }
};