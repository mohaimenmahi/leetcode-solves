class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        string chain;

        for(int i = 0; i < words.size(); i++) {
            chain += words[i];
            chain += '.';
        }

        int len = chain.size(), idx = 0, taken = 0;
        vector<int> res;

        for(int i = 0; i < len; i++) {
            if(chain[i] == x && !taken) {
                res.push_back(idx);
                taken = 1;
            } else if(chain[i] == '.') {
                taken = 0;
                idx++;
            }
        }

        return res;
    }
};