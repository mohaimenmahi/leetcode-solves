class Solution {
public:
    int minimumLength(string s) {
        vector<int> cnt(26, 0);
        int n = s.size();

        int res = 0;
        for(int i = 0; i < n; i++) cnt[s[i]-'a']++;

        for(int i = 0; i < 26; i++) {
            if(cnt[i] == 0) continue;
            
            if(cnt[i] % 2) res++;
            else res += 2;
        }

        return res;
    }
};