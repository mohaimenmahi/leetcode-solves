class Solution {
private:
    vector<int> cntChars(string word) {
        vector<int> cnt(26, 0);
        for(int j = 0; j < word.size(); j++) {
            cnt[word[j]-'a']++;
        }

        return cnt;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int m = words1.size(), n = words2.size();

        vector<int> freq(26, 0);

        for(int i = 0; i < n; i++) {
            vector<int> bCnt = cntChars(words2[i]);
            for(int j = 0; j < 26; j++) freq[j] = max(freq[j], bCnt[j]);
        }

        vector<string> res;

        for(int i = 0; i < m; i++) {
            vector<int> aCnt = cntChars(words1[i]);

            bool isValid = true;
            for(int j = 0; j < 26; j++) {
                if(freq[j] > aCnt[j]) {
                    isValid = false;
                    break;
                }
            }

            if(isValid) res.push_back(words1[i]);
        }

        return res;
    }
};