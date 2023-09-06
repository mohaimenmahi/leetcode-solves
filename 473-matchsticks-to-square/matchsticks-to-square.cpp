class Solution {
private:
    bool backtrack(
        int idx,
        int& len,
        vector<int>& sides,
        vector<int>& sticks
    ) {
        if(idx == sticks.size()) return true;

        for(int i = 0; i < 4; i++) {
            if(sides[i]+sticks[idx] <= len) {
                sides[i] += sticks[idx];
                if(backtrack(idx+1, len, sides, sticks))
                    return true;
                sides[i] -= sticks[idx];
            }
        }

        return false;
    }
public:
    bool makesquare(vector<int>& sticks) {
        int p = 0;

        for(int i = 0; i < sticks.size(); i++) p += sticks[i];

        if(p % 4) return false;

        int len = p / 4;

        vector<int> sides(4, 0);

        sort(sticks.begin(), sticks.end());
        reverse(sticks.begin(), sticks.end());

        return backtrack(0, len, sides, sticks);
    }
};