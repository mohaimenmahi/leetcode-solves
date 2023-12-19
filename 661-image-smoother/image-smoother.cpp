class Solution {
private:
    int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    int isValid(int row, int col, int m, int n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> sum(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int cellSum = img[i][j];
                int cellCount = 1;

                for(int k = 0; k < 8; k++) {
                    int row = i + dx[k];
                    int col = j + dy[k];

                    if(isValid(row, col, m, n)) {
                        cellSum += img[row][col];
                        cellCount++;
                    }
                }

                sum[i][j] = cellSum / cellCount;
            }
        }

        return sum;
    }
};