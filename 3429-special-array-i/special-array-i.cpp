class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(abs(nums[i] - nums[i-1]) % 2 == 0) return false; 
        }

        return true;
    }
};