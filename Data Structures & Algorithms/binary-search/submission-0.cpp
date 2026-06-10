class Solution {
   public:
    int findElement(vector<int>& nums, int target, int start, int end) {
        if (end < start) {
            return -1;
        }
        int medium = start + (end - start) / 2;

        if (nums[medium] > target) {
            end = medium -1;
            return findElement(nums, target, start, end);
        } else if (nums[medium] < target) {
            start = medium + 1;
            return findElement(nums, target, start, end);
        } else {
            return medium;
        }
    }

    int search(vector<int>& nums, int target) {
        return findElement(nums, target, 0, nums.size() - 1);
    }
};
