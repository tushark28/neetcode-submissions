class Solution {
   public:
    bool findElementInVector(vector<int>& nums, int target, int low, int high) {
        if (high < low) {
            return false;
        }
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return true;
        } else if (nums[mid] > target) {
            return this->findElementInVector(nums, target, low, mid - 1);
        } else {
            return this->findElementInVector(nums, target, mid + 1, high);
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] <= target && target <= matrix[mid][matrix[mid].size() - 1]) {
                return this->findElementInVector(matrix[mid], target, 0, matrix[mid].size() - 1);
            } else if (matrix[mid][0] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};