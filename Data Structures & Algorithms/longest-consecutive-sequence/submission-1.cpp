class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 1){
            return 0;
        }
        int ans = 1;
        unordered_set<int> st(nums.begin(), nums.end());

        for (auto& num : nums) {
            if (st.count(num - 1)) {
                continue;
            }
            int consecutives = 1;
            for (int i = num +1; ;i++){
                if(!st.count(i)){
                    ans = max(ans, consecutives);
                    break;
                }
                consecutives ++;
            }
        }
        return ans;
    }
};
