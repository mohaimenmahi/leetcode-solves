class Solution {
private:
    unordered_set<int> cols, neg, pos;

    void backtrack(int row, int& n, int& ans) {
        if(row == n) {
            ans++;
            return;
        }

        for(int col = 0; col < n; col++) {
            if(cols.find(col) == cols.end() &&
               neg.find(row-col) == neg.end() &&
               pos.find(row+col) == pos.end()
            ) {
                cols.insert(col);
                neg.insert(row-col);
                pos.insert(row+col);

                backtrack(row+1, n, ans);

                cols.erase(col);
                neg.erase(row-col);
                pos.erase(row+col);
            }
        }
    }
public:
    int totalNQueens(int n) {
        int ans = 0;

        backtrack(0, n, ans);

        return ans;
    }
};