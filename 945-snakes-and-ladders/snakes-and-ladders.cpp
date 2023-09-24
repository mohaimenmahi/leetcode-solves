class Solution {
private:
    pair<int,int> numToPos(int num, int n) {
        int row = (num - 1) / n;
        int col = (num - 1) % n;

        if(row % 2) col = n - 1 - col;

        return {row, col};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        queue<pair<int,int>> q; // [cur, moves]; moves is how much moves needed to reach cur
        unordered_set<int> vis;

        reverse(board.begin(), board.end());

        q.push({1, 0}); // will start from 1, 0 moves needed
        vis.insert(1);

        while(!q.empty()) {
            int cur = q.front().first;
            int moves = q.front().second; // moves needed to come to that square
            q.pop();

            for(int i = 1; i <= 6; i++) {
                int next = cur + i;

                pair<int, int> pos = numToPos(next, n);
                int r = pos.first, c = pos.second;
                if(board[r][c] != -1) next = board[r][c];
                if(next == n * n) return moves + 1;
                if(vis.find(next) == vis.end()) {
                    vis.insert(next);
                    q.push({next, moves + 1});
                }
            }
        }   

        return -1;
    }
};