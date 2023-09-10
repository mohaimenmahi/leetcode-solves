class Solution {
private:
    string backtrack(int idx, unordered_set<string>& st, string ans) {
        if(idx == ans.size()) {
            if(st.find(ans) == st.end()) return ans;
            else return "null";
        }

        // idx'th digit will be 0, go for next
        string res = backtrack(idx+1, st, ans);
        if(res != "null") return res;

        // idx'th digit is 1, go for next
        ans[idx] = '1';
        res = backtrack(idx+1, st, ans);
        
        if(res !="null") return res;
        else return "null";
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> st;
        string ans = ""; 

        for(int i = 0; i < n; i++) {
            st.insert(nums[i]);
            ans.push_back('0');
        }

        return backtrack(0, st, ans);
    }
};