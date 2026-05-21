class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> elements;

        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];
            auto it = elements.find(difference);
            if (it != elements.end()) {
                return vector<int>{ it->second, i };
            } else {
                elements[nums[i]] = i;
            }

        }
        return vector<int>{0, 0};
    }
};
