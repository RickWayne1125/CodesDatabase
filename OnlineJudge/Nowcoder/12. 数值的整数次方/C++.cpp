class Solution {
public:
    double Power(double base, int exponent) {
        if (base == 1 || base == 0) return base;
        double ans = 1;
        int flag = 1;
        if (exponent < 0) {
            flag = 0;
            exponent = abs(exponent);
        }
        ans = pow(base, exponent / 2);
        ans = ans * ans;
        if (exponent % 2 == 1) {
            ans *= base;
        }
        if (!flag)   return 1 / ans;
        return ans;
    }
};