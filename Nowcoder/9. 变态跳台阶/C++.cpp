class Solution {
public:
    int jumpFloorII(int n) {
        if (n <= 1) {
            return 1;
        }
        else if (n == 2) {
            return 2;
        }
        else if (n > 2) {
            return 2 * jumpFloorII(n - 1);
        }
    }
};