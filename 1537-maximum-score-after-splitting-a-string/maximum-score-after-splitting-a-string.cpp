class Solution {
public:
    int maxScore(string s) {
        int n = s.size();

        int left = 0, right = 0;

        for(int i = 0; i < n; i++) if(s[i] == '1') right++;

        int ans = INT_MIN;

        for(int i = 0; i < n-1; i++) {
            left += s[i] == '0';
            right -= s[i] == '1';

            ans = max(ans, left + right);
        }

        return ans;
    }
};