class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0;

        int best = INT_MIN;

        for(int i = 0; i < s.size()-1; i++) {
            zeros += s[i] == '0';
            ones += s[i] == '1';

            best = max(best, zeros - ones);
        }

        if(s[s.size()-1] == '1') ones++;

        return best + ones;
    }
};