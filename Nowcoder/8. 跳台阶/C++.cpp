class Solution {
public:
    int jumpFloor(int n) {
        if (n == 0)    return 1;
        if (n <= 2) {
            return n;
        }
        int a = 1;
        int b = 2;
        while (n > 1) {
            b = a + b;
            a = b - a;
            n--;
        }
        return a;
    }
};