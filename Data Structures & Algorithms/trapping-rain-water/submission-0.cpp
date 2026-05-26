class Solution {
   public:
    int trap(vector<int>& height) {
        vector<int> prefixMax(height.size()), suffixMax(height.size());

        prefixMax[0] = 0;
        suffixMax[height.size() - 1] = 0;

        for (int i = 1; i < height.size() - 1; i++) {
            prefixMax[i] = max(prefixMax[i-1], height[i-1]);
            suffixMax[height.size() - i -1] = max(suffixMax[height.size() -i], height[height.size() -i]);
        }

        int ans = 0;
        for (int i = 0; i< height.size(); i++){
            int holdingCapacity = min(prefixMax[i], suffixMax[i]) - height[i];
            if (holdingCapacity > 0){
                ans += holdingCapacity;
            }
        }
        return ans;
    }
};
