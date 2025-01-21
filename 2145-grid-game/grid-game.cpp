class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<long long>> prefix(2, vector<long long>(n, 0));

        prefix[0][0] = (long long) grid[0][0];
        prefix[1][0] = (long long) grid[1][0];

        for(int i = 1; i < n; i++) {
            prefix[0][i] = prefix[0][i-1] + (long long) grid[0][i];
            prefix[1][i] = prefix[1][i-1] + (long long) grid[1][i];
        } 

        long long res = LLONG_MAX;

        for(int i = 0; i < n; i++) {
            long long first = prefix[0][n-1] - prefix[0][i];
            long long second = i > 0 ? prefix[1][i-1] : 0;

            res = min(res, max(first, second));
        }

        return res;
    }
};