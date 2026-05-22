class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroesCount = 0;
        long long int product = 1;

        for (auto &num : nums){
            if (num == 0){
                zeroesCount ++ ;
                continue;
            }
            product *= num;
        }

        if (zeroesCount > 1){
            fill(nums.begin(), nums.end(), 0);
            return nums;
        }

        for (auto &num: nums){
            if (num == 0){
                num = product;
            }
            else if (zeroesCount > 0){
                num = 0;
            }
            else {
                num = product/num;
            }
        }

        return nums;
    }
};
