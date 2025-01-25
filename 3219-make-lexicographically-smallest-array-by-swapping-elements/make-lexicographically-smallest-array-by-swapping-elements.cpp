class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> numCpy(nums);

        unordered_map<int, int> numsToGrp;
        unordered_map<int, queue<int>> grpToList;

        sort(numCpy.begin(), numCpy.end());

        int currGrp = 0;
        numsToGrp[numCpy[0]] = 0;

        grpToList[0].push(numCpy[0]);

        for(int i = 1; i < n; i++) {
            if(numCpy[i]-numCpy[i-1] > limit) currGrp++;

            numsToGrp[numCpy[i]] = currGrp;
            grpToList[currGrp].push(numCpy[i]);
        }

        vector<int> res;

        for(int i = 0; i < n; i++) {
            int num = nums[i];

            int grp = numsToGrp[num];

            int val = grpToList[grp].front();
            grpToList[grp].pop();

            res.push_back(val);
        }

        return res;
    }
};