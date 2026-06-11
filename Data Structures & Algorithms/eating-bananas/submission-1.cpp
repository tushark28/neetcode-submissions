class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_val = *std::max_element(piles.begin(), piles.end());
        int low = 1; long high = max_val * piles.size();
        long ans = high;
        while (low <= high) {
            long mid = low + (high - low) / 2;

            int time = 0;

            for (auto& pile : piles) {
                time += ceil(double(pile) / mid);
            }

            if (time <= h) {
                ans = min(ans, mid);
                high = mid -1;
            } else {
                low = mid +1;
            }
        }
        return ans;
    }
};
