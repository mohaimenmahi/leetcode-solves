class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> ans(n, 0);

        int leftCount = 0, leftMoves = 0;
        int rightCount = 0, rightMoves = 0;

        for(int i = 0; i < n; i++) {
            ans[i] += leftMoves;
            leftCount += boxes[i]-'0';
            leftMoves += leftCount;

            int j = n-1-i;
            ans[j] += rightMoves;
            rightCount += boxes[j]-'0';
            rightMoves += rightCount;
        }

        return ans;
    }
};