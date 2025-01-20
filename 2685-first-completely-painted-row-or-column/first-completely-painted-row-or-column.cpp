class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int sz = arr.size();

        vector<int> numToIndex(sz+1);

        for(int i = 0; i < sz; i++) {
            numToIndex[arr[i]] = i;
        }

        int res = sz;

        // for each row
        for(int i = 0; i < m; i++) {
            int maxIdx = INT_MIN;
            for(int j = 0; j < n; j++) {
                maxIdx = max(maxIdx, numToIndex[mat[i][j]]);
            }

            res = min(res, maxIdx);
        }

        // for each column
        for(int i = 0; i < n; i++) {
            int maxIdx = INT_MIN;
            for(int j = 0; j < m; j++) {
                maxIdx = max(maxIdx, numToIndex[mat[j][i]]);
            }

            res = min(res, maxIdx);
        }

        return res;
    }
};