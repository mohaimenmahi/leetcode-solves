class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() == k) return true;
        if(s.size() < k) return false;

        vector<int> cnt(26, 0);

        for(int i = 0; i < s.size(); i++) cnt[s[i]-'a']++;

        int odds = 0;

        for(int i = 0; i < 26; i++) {
            if(cnt[i] % 2) odds++;
        }

        return odds <= k;
    }
};