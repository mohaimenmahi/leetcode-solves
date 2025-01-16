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
        int res = num1;

        int target = countSetBits(num2);
        int setBits = countSetBits(res);

        // to set and unset bits, we will start from left (Least Significant Bits)
        // because the LSB increases or decreases the value by 1
        // as we need to be as close as possible with num1, we need to do one by one
        int idx = 0;

        // if the number of set bits in potential result is less then target set bits
        while(setBits < target) {
            if(!isSetBit(res, idx)) {
                setBits++;
                res |= 1 << idx;
            }
            idx++; 
        }

        // or number of set bits are greater then the target set bits
        while(setBits > target) {
            if(isSetBit(res, idx)) {
                res = res & ~(1 << idx);
                setBits--;
            }
            idx++;
        }

        return res;
    }
};