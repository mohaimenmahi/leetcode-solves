class Solution {
public:
    int maxScore(string s) {
        int n = s.size();

        vector<int> prefix(n, 0), suffix(n, 0);

        prefix[0] = s[0] == '0';
        suffix[n-1] = s[n-1] == '1';

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + (s[i] == '0');
            suffix[n-i-1] = suffix[n-i] + (s[n-i-1] == '1');
        }

        int ans = INT_MIN;

        for(int i = 0; i < n-1; i++) {
            ans = max(ans, prefix[i] + suffix[i+1]);
        }

        return ans;
    }
};