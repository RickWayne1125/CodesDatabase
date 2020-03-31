class Solution {
public:
    double Power(double base, int exponent) {
        double ans = 1;
        int flag = 1;
        if (exponent < 0) {
            flag = 0;
            exponent = -exponent;
        }
        for (int i = 0; i < exponent; i++) {
            ans *= base;
        }
        if (!flag)   return 1 / ans;
        return ans;
    }
};