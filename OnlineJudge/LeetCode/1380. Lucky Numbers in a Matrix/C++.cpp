#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        for (int i = 0; i < matrix.size(); i++) {
            int minpos = min_element(matrix[i].begin(), matrix[i].end()) - matrix[i].begin();
            // [i][minpos]
            int flag = 1;
            for (int j = 0; j < matrix.size(); j++) {
                if (matrix[j][minpos] > matrix[i][minpos]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                ans.push_back(matrix[i][minpos]);
            }
        }
        return ans;
    }
};