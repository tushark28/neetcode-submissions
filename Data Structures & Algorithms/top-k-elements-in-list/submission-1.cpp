class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (auto& i : nums) {
            mp[i]++;
        }
        vector<vector<int>> buckets(nums.size() + 1);
        vector<int> ans;

        for (auto& i : mp) {
            buckets[i.second].push_back(i.first);
        }

        for (int i = buckets.size() - 1; i >= 1; i--) {
            for (int j = 0; j < buckets[i].size(); j++) {
                if (ans.size() == k) {
                    return ans;
                }
                ans.push_back(buckets[i][j]);
            }
        }
        return ans;
    }
};
