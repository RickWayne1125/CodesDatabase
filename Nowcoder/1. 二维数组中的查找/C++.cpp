class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.size() == 0) {
            return false;
        }
        int i = 0;
        int j = array[0].size()-1;
        while (i != array.size() && j >= 0) {
            if (array[i][j] == target) {
                return true;
            }
            else if (array[i][j] < target) {
                i++;
            }
            else if (array[i][j] > target) {
                j--;
            }
        }
        return false;
    }
};