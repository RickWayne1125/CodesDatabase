class Solution {
public:
    int  NumberOf1(int n) {
        bitset<32> temp(n);
        int ans = temp.count();
        return ans;
    }
};