class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> max;
        vector<int> ans(temperatures.size(), 0);

        for (int i = 0; i< temperatures.size(); i++) {
            while (!max.empty() && max.top().first < temperatures[i]){
                int index = max.top().second;
                max.pop();
                ans[index] = i - index;
            }
            max.push({temperatures[i], i});
        }

        return ans;
    }
};
