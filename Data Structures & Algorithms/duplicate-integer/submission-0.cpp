class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map <int,int> numMap ;

        for (auto &i : nums) {
            if (numMap.find(i) == numMap.end()){
                numMap[i] = 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
    
};