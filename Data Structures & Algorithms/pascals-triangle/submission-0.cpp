class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {{1}};
        for (int i = 1; i < numRows; i++) {
            vector<int> row = {1};
            vector<int> &lastRow = ans.back();
            for (int j = 0; j < lastRow.size() - 1; j++) {
                row.push_back(lastRow[j] + lastRow[j+1]);
            }
            row.push_back(1);

            ans.push_back(row);
        }
        return ans;
    }
};