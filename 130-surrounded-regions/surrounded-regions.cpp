class Solution {
private:
    void dfs(
        int r,
        int c,
        int m,
        int n,
        vector<vector<char>>& board
    ) {
        if(r < 0 || r == m || c < 0 || c == n || board[r][c] != 'O') return;

        board[r][c] = 'E';

        dfs(r+1, c, m, n, board);   
        dfs(r-1, c, m, n, board);
        dfs(r, c+1, m, n, board);
        dfs(r, c-1, m, n, board);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++) {
            dfs(i, 0, m, n, board);
            dfs(i, n-1, m, n, board);
        }

        for(int j = 0; j < n; j++) {
            dfs(m-1, j, m, n, board);
            dfs(0, j, m, n, board);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'E') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] ='X';
            }
        }
    }
};