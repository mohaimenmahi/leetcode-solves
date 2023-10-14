/* backtracking */

class Solution {
private:
    void dfs(
        int i, 
        vector<int>& nums, 
        vector<int> list, 
        vector<vector<int>>& res
    ) {
        // iuf index is out of bound
        if(i >= nums.size()) {
            res.push_back(list);
            return;
        }

        // take the element of that index
        list.push_back(nums[i]);
        // go to next index
        dfs(i+1, nums, list, res);

        // do not take the element, so pop it back
        list.pop_back();
        // go to the next index
        dfs(i+1, nums, list, res);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> list;
        vector<vector<int>> res;

        dfs(0, nums, list, res);

        return res;
    }
};