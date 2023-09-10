class Solution {
private:
    bool isUnique(string s) {
        vector<int> v(26, 0);

        for(int i = 0; i < s.size(); i++) {
            if(v[s[i]-'a'] > 0) return false;
            v[s[i]-'a']++;
        }

        return true;
    }

    void backtrack(int i, vector<string>& arr, string cur, int& ans) {
        if(i >= arr.size()) return;

        for(int j = i; j < arr.size(); j++) {
            string str = cur + arr[j];
            if(isUnique(str)) {
                int len = str.size();
                ans = max(ans, len);
                backtrack(j + 1, arr, str, ans);
            }
        }
    }
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;

        backtrack(0, arr, "", ans);

        return ans;
    }
};