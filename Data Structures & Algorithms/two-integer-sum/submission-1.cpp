class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> elements;

        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];
            auto it = elements.find(difference);
            if (it != elements.end()) {
                return {it->second, i};
            }
            elements[nums[i]] = i;
        }
        return {};
    }
};
