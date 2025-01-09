class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;

        for(int i = 0; i < words.size(); i++) {
            int idx = 0;

            while(idx < pref.size() && pref.size() <= words[i].size()) {
                if(pref[idx] == words[i][idx]) idx++;
                else break;
                
                if(idx == pref.size()) ans++;
            }
        }

        return ans;
    }
};