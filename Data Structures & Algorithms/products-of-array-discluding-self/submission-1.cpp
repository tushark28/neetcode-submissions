class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> suffix(nums.size());
        vector<int> prefix(nums.size());

        suffix[0] = nums[0];
        prefix[0] = nums[nums.size() - 1];

        for (int i = 1; i < nums.size(); i++) {
            suffix[i] = suffix[i - 1] * nums[i];
            prefix[i] = prefix[i - 1] * nums[nums.size() - i - 1];
        }

        for (int i = 0; i < nums.size(); i++) {
            int prefixVal = ((int)nums.size() - i - 2) >= 0 ? prefix[nums.size() - i - 2] : 1;
            int suffixVal = i - 1 >= 0 ? suffix[i - 1] : 1;
            nums[i] = prefixVal * suffixVal;
        }

        return nums;
    }
};
