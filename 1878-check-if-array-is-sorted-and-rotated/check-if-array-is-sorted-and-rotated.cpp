class Solution {
private:
    bool isSorted(int start, vector<int>& nums) {
        int idx = 0;
        int n = nums.size();
        int mini = nums[start];
        while((start + idx) % n < n && idx < n) {
            int pos = (start + idx) % n;
            if(mini > nums[pos]) return false;
            
            mini = nums[pos];
            idx++;
        }

        return true;
    }
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        int  mini = 101;

        for(int i = 0; i < n; i++) mini = min(mini, nums[i]);

        unordered_set<int> minIdxs;
        for(int i = 0; i < n; i++) {
            if(mini == nums[i]) minIdxs.insert(i);
        }

        for(int i:minIdxs) {
            if(isSorted(i, nums)) return true;
        }

        return false;
    }
};