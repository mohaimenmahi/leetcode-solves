class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        
        vector<int> indexes(n+2);
        vector<char> symbols(n+2);

        int len = 1;
        indexes[0] = -1;
        symbols[0] = 'L';

        for(int i = 0; i < n; i++) {
            if(dominoes[i] != '.') {
                indexes[len] = i;
                symbols[len] = dominoes[i];
                len++;
            }
        }

        indexes[len] = n;
        symbols[len++] = 'R';

        vector<char> ans(dominoes.begin(), dominoes.end());

        for(int idx = 0; idx < len - 1; idx++) {
            int i = indexes[idx], j = indexes[idx+1];
            char x = symbols[idx], y = symbols[idx+1];

            if(x == y) {
                for(int k = i+1; k < j; k++) ans[k] = x;
            } else if(x > y) {
                for(int k = i+1; k < j; k++) {
                    ans[k] = k-i == j-k ? '.' : k-i > j-k ? 'L' : 'R';
                }
            }
        }

        string res(ans.begin(), ans.end());

        return res;
    }
};