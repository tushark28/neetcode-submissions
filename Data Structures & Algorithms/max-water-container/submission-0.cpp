class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0, e = heights.size() - 1, s = 0;
        while (s < e) {
            maxArea = max(maxArea, min(heights[s], heights[e]) * (e -s));
            cout << s << " "<< e << " "<< e -s << " "<< maxArea<< endl;
            if (heights[s] > heights[e]){
                e --;
            }
            else {
                s ++;
            }
        }
        return maxArea;
    }
};
