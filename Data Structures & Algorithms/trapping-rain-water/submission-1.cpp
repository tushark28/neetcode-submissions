class Solution {
   public:
    int trap(vector<int>& height) {
        int l = 0, maxL = 0, maxR = 0, ans = 0, r = height.size() - 1;

        while (l < r){
            maxL = max(maxL, height[l]);
            maxR = max(maxR, height[r]);

            ans += (maxL - height[l]) + (maxR - height[r]);

            height[l] > height[r] ? r-- : l++;
        }
        return ans;
    }
};
