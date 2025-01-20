class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int sz = arr.size();

        vector<pair<int, int>> cellMap(sz+1);
        vector<int> rows(m, n), cols(n, m);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cellMap[mat[i][j]] = {i, j};
            }
        }

        int res = 0;

        while(res < sz) {
            int val = arr[res];
            int row = cellMap[val].first, col = cellMap[val].second;

            rows[row]--, cols[col]--;
            if(rows[row] <= 0 || cols[col] <= 0) return res;
            res++;
        }

        return sz-1;
    }
};