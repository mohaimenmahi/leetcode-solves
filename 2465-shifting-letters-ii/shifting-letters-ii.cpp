class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();

        vector<int> diff(n, 0);

        for(auto q:shifts) {
            int l = q[0], r = q[1], d = q[2];
            if(d) {
                diff[l]++;
                if(r+1 < n) diff[r+1]--;
            } else {
                diff[l]--;
                if(r+1 < n) diff[r+1]++;
            }
        }

        int shiftCounts = 0;
        string res;

        for(int i = 0; i < n; i++) {
            shiftCounts = (shiftCounts + diff[i]) % 26;

            char newChar = 'a' + (s[i] - 'a' + shiftCounts + 26) % 26;
            res.push_back(newChar);
        }

        return res;
    }
};