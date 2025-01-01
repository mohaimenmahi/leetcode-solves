class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0;
        int n = s.size();

        int best = INT_MIN;

        for(int i = 0; i < n-1; i++) {
            zeros += s[i] == '0';
            ones += s[i] == '1';

            best = max(best, zeros - ones);
        }

        if(s[n-1] == '1') ones++;

        return best + ones;
    }
};