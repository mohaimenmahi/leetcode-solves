class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1), last(26, -1);

        for(int i = 0; i < s.size(); i++) {
            int idx = s[i]-'a';
            if(first[idx] == -1) first[idx] = i;
            last[idx] = i;
        }

        int res = 0;
        for(int i = 0; i < 26; i++) {
            if(last[i] - first[i] >= 2) {
                unordered_set<char> unq;
                for(int j = first[i]+1; j < last[i]; j++) unq.insert(s[j]);

                res += unq.size();
            }
        }

        return res;
    }
};