class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) sum += (long long) nums[i];

        long long curr = 0;
        int res = 0;

        for(int i = 0; i < n-1; i++) {
            curr += (long long) nums[i];

            if(curr >= sum - curr) res++;
        }

        return res;
    }
};