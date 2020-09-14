class Solution {
public:
    int rectCover(int n) {
        if (n == 0)    return 0;
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