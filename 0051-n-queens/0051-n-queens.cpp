class Solution {
public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> lowerDiagnolCheck;
    unordered_map<int, bool> upperDiagnolCheck;

    void storeSolution(vector<vector<string>>& ans, vector<vector<char>>& board,
                       int n) {
        vector<string> tempAns;
        for (int i = 0; i < n; i++) {
            string output = "";
            for (int j = 0; j < n; j++) {
                output.push_back(board[i][j]);
            }
            // string is ready
            tempAns.push_back(output);
        }
        // vector of string is ready
        ans.push_back(tempAns);
    }

    bool isSafe(int row, int col, vector<vector<char>>& board) {
        // brute for -> traverse board -> T.C -> n^2
        // Linear T.C ->

        // check for row
        if (rowCheck[row] == true) {
            // not safe
            return false;
        }
        // check for upper diagnol
        if (upperDiagnolCheck[row - col] == true) {
            // not safe
            return false;
        }
        // check lower diagnol
        if (lowerDiagnolCheck[row + col] == true) {
            // not safe
            return false;
        }
        // else safe to place
        return true;
    }
    void solve(int n, vector<vector<char>>& board, vector<vector<string>>& ans,
               int col) {

        // base case
        if (col >= n) {
            // means all the queen placed successfully
            // store the board arrangement in ans
            storeSolution(ans, board, n);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board)) {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                lowerDiagnolCheck[row + col] = true;
                upperDiagnolCheck[row - col] = true;
                solve(n, board, ans, col + 1);
                // backtrack
                board[row][col] = '.';
                rowCheck[row] = false;
                lowerDiagnolCheck[row + col] = false;
                upperDiagnolCheck[row - col] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        int col = 0;
        solve(n, board, ans, col);
        return ans;
    }
};