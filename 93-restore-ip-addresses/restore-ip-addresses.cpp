class Solution {
private:
    bool isValid(string s, int start, int end) {
        int num = stoi(s.substr(start, end-start+1));
        return num < 256 && (start == end || s[start] != '0');
    }
    void backtrack(
        int idx,
        int dots,
        string s,
        string cur, 
        vector<string>& ans
    ) {
        if(dots == 4 && idx == s.size()) {
            cur.pop_back(); // removing trailing dot
            ans.push_back(cur);
            return;
        }

        if(dots > 4) return;

        int size = s.size();
        int limit = min(idx+3, size);

        for(int i = idx; i < limit; i++) {
            if(isValid(s, idx, i)) {
                backtrack(i+1, dots+1, s, cur + s.substr(idx, i-idx+1) + '.', ans);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;

        if(s.size() > 12) return ans;

        backtrack(0, 0, s, "", ans);

        return ans;
    }
};