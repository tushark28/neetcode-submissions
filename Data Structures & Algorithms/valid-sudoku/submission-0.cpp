class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> columns(9);
        vector<unordered_set<char>> boxes(9);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                char val = board[i][j];
                if (val == '.'){
                    continue;
                }
                int box = (i / 3) * 3 + (j / 3);
                if (rows[i].count(val) || columns[j].count(val) || boxes[box].count(val)) {
                    return false;
                }

                rows[i].insert(val);
                columns[j].insert(val);
                boxes[box].insert(val);
            }
        }

        return true;
    }
};
