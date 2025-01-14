class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> ma, mb;
        int n = A.size();

        vector<int> res(n, 0);

        for(int i = 0; i < n; i++) {
            int cnt = 0;
            if(A[i] == B[i]) cnt++;

            if(mb.find(A[i]) != mb.end()) cnt++;
            if(ma.find(B[i]) != ma.end()) cnt++;

            if(i > 0) res[i] = res[i-1] + cnt;
            else res[i] = cnt;

            ma.insert(A[i]);
            mb.insert(B[i]);
        }

        return res;
    }
};