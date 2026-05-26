class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrefix = prices[0], ans =0;

        for (auto &price: prices){
            ans = max(price - minPrefix,ans);
            minPrefix = min(price, minPrefix);
        }

        return ans;
    }
};
