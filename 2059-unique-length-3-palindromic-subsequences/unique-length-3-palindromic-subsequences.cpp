class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> st;

        for(char c:s) st.insert(c);

        int res = 0;

        for(char c:st) {
            int ff = -1, ll = -1;

            for(int i = 0; i < s.size(); i++) {
                if(s[i] == c) {
                    if(ff == -1) ff = i;
                    ll =i;
                }
            }

            if(ll - ff >= 2) {
                unordered_set<char> unq;

                for(int j = ff+1; j < ll; j++) unq.insert(s[j]);

                res += unq.size();
            }
        }

        return res;
    }
};