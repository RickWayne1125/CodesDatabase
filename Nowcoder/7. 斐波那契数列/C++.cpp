class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0) {
            return 0;
        }
        else if (n > 0 && n < 2) {
            return 1;
        }
        else if (n >= 2) {
            int a = 0;
            int b = 1;
            while (n > 0) {
                b = a + b;
                a = b - a;
                n--;
            }
            return a;
        }
    }
};