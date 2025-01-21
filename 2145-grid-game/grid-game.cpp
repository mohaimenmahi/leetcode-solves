class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long res = LLONG_MAX;

        long long firstRow = 0LL, lastRow = 0;

        for(int i = 0; i < n; i++) firstRow += (long long) grid[0][i];

        for(int i = 0; i < n; i++) {
            firstRow -= (long long) grid[0][i];
            res = min(res, max(firstRow, lastRow));

            lastRow += grid[1][i];
        }

        return res;
    }
};