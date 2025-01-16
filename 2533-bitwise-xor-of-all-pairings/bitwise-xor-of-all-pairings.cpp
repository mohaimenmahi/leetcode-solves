class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        
        if(!(m % 2) && !(n % 2)) return 0;

        int res1 = 0, res2 = 0;

        if(m % 2) {
            for(int i:nums2) res1 ^= i; 
        }
        
        if(n % 2) {
            for(int i:nums1) res2 ^= i;
        }

        return res1 ^ res2;
    }
};