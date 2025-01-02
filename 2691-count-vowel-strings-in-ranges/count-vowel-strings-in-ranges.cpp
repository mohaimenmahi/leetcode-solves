class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    bool hasVowel(string s) {
        int n = s.size();

        return isVowel(s[0]) && isVowel(s[n-1]);
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), m = queries.size();

        vector<int> prefix(n, 0);

        prefix[0] = hasVowel(words[0]);

        for(int i = 1; i < n; i++) prefix[i] = prefix[i-1] + hasVowel(words[i]);

        vector<int> res;

        for(int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1];

            if(l > 0) res.push_back(prefix[r]-prefix[l-1]);
            else res.push_back(prefix[r]);
        }

        return res;
    }
};