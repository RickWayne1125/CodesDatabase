class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        sort(nums.begin(),nums.end());
        set<int> s(nums.begin(), nums.end());
        nums.assign(s.begin(), s.end());
        return nums.size();
    }
};