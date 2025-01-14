class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ma(n+1, 0), mb(n+1, 0);

        vector<int> res(n, 0);

        for(int i = 0; i < n; i++) {
            int cnt = 0;
            if(A[i] == B[i]) cnt++;

            if(mb[A[i]]) cnt++;
            if(ma[B[i]]) cnt++;

            if(i > 0) res[i] = res[i-1] + cnt;
            else res[i] = cnt;

            ma[A[i]] = 1;
            mb[B[i]] = 1;
        }

        return res;
    }
};