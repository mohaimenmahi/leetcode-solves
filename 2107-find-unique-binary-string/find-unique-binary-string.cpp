class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> st;
        string ans = "";

        for(int i = 0; i < n; i++) {
            st.insert(nums[i]);
            ans.push_back('0');
        }

        int j = 0;
        while(st.find(ans) != st.end()) {
            if(ans[j] == '0') ans[j] = '1';
            else {
                ans[j] = '0';
                ans[j+1] = '1';
            }
            j++;
        }
        
        return ans;
    }
};