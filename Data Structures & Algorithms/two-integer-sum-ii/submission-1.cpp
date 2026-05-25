class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;

        while (start < end) {
            if (numbers[start] + numbers[end] == target) {
                return {start + 1, end + 1};
            }
            if (numbers[start + 1] + numbers[end] <= target) {
                start++;
            } else if (numbers[start] + numbers[end - 1] >= target) {
                end--;
            } else {
                start++;
                end--;
            }
        }
        return {};
    }
};
