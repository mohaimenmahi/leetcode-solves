class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> rowCnt(m, 0), colCnt(n, 0); // number of servers in each row and each column

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }

        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    res += (rowCnt[i] > 1) || (colCnt[j] > 1); // current cell is a part of connectable server
                }
            }
        }

        return res;
    }
};