class Solution {
private:
    bool isPrefixAndSuffix(string str1, string str2) {
        if(str1.size() > str2.size()) return false;

        bool res = false;

        int i = 0, d = str2.size() - str1.size();
        while(i < str1.size()) {
            if(str1[i] == str2[i] && str1[i] == str2[i+d]) i++;
            else break;

            if(i == str1.size()) res = true;;
        }

        return res;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0;

        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < i; j++) {
                res += isPrefixAndSuffix(words[j], words[i]);
            }
        }

        return res;
    }
};