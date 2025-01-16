class Solution {
private:
    int countSetBits(int n) {
        int cnt = 0;

        while(n > 0) {
            cnt += n & 1;
            n = n >> 1;
        }

        return cnt;
    }
    bool isSetBit(int n, int idx) {
        return n & (1 << idx);
    }
public:
    int minimizeXor(int num1, int num2) {
        int res = 0;

        int target = countSetBits(num2);
        int setBits = 0;

        int idx = 31;

        while(setBits < target) {
            // target - setBits > idx = the remainig bits to make setBits == target is greater 
            // than the bits available to the right
            if(isSetBit(num1, idx) || target - setBits > idx) {
                res |= 1 << idx;
                setBits++;
            }
            idx--;
        }

       
        return res;
    }
};