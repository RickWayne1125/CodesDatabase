class Solution {
public:
    int minNumberInRotateArray(vector<int> numbers) {
        if (numbers.size() == 0)    return 0;
        int n = numbers.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (numbers[mid] > numbers[right]) left = mid + 1;
            else if (numbers[mid] == numbers[right]) right--;
            else right = mid;
        }
        return numbers[left];
    }
};