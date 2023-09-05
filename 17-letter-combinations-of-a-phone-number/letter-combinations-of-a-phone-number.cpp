class Solution {
private:
    void generateMap(vector<string>& mp) {
        int c = 0;
        for(int i = 2; i <= 9; i++) {
            int limit = i == 7 || i == 9 ? c + 4 : c + 3;
            for(int j = c; j < limit; j++) {
                mp[i].push_back('a'+c);
                c++;
            }
        }
    }

    void backtrack(
        int idx,
        vector<string>& mp,
        string s,
        string cur,
        vector<string>& ans
    ) {
        if(cur.size() == s.size()) {
            ans.push_back(cur);
            return;
        }

        for(int i = idx; i < s.size(); i++) {
            int c = s[idx] - '0';
            for(int j = 0; j < mp[c].size(); j++) {
                cur.push_back(mp[c][j]);
                backtrack(i+1, mp, s, cur, ans);
                cur.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mp(10, "");
        vector<string> ans;

        if(!digits.size()) return ans;

        generateMap(mp);

        backtrack(0, mp, digits, "", ans);
        
        return ans;
    }
};