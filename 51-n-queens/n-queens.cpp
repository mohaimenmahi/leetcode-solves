class Solution {
private:
    void backtrack(
        int r, 
        int n,
        unordered_set<int>& col, 
        unordered_set<int>& neg, 
        unordered_set<int>& pos, 
        vector<string>& board,
        vector<vector<string>>& ans
    ) {
        if(r == n) {
            ans.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++) {
            if(col.find(c) == col.end() &&
                neg.find(r-c) == neg.end() &&
                pos.find(r+c) == pos.end()
            ) {
                col.insert(c);
                neg.insert(r-c);
                pos.insert(r+c);
                board[r][c] = 'Q';

                backtrack(r+1, n, col, neg, pos, board, ans);

                col.erase(c);
                neg.erase(r-c);
                pos.erase(r+c);
                board[r][c] = '.';
            }
        } 
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int> col, pos, neg;

        vector<string> board;
        vector<vector<string>> ans;

        for(int r = 0; r < n; r++) {
            string s = "";
            for(int c = 0; c < n; c++) s.push_back('.');
            board.push_back(s);
        }

        backtrack(0, n, col, neg, pos, board, ans);

        return ans;
    }
};   