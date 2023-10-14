class Solution {
private:
    void dfs(
        string word, 
        string stopWord, 
        unordered_map<string, int>& level,
        vector<string>& seq, 
        vector<vector<string>>& ans
    ) {
        if(word == stopWord) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int len = word.size();
        int steps = level[word];

        for(int i = 0; i < len; i++) {
            char w = word[i];
            for(char c = 'a'; c <= 'z'; c++) {
                word[i] = c;

                if(level.find(word) != level.end() && level[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, stopWord, level, seq, ans);
                    seq.pop_back();
                } 
            }
            word[i] = w;
        }
    }
public:
    vector<vector<string>> findLadders(
        string beginWord, 
        string endWord, 
        vector<string>& wordList
    ) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, int> level;
        
        vector<vector<string>> ans;
        
        queue<string> q;
        q.push(beginWord);
        dict.erase(beginWord);
        level[beginWord] = 1;

        while(!q.empty()) {
            string word = q.front();
            q.pop();
            
            int steps = level[word];
            if(word == endWord) break;
            
            for(int i = 0; i < word.size(); i++) {
                char w = word[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if(dict.count(word)) {
                        q.push(word);
                        dict.erase(word);
                        level[word] = steps + 1;
                    }
                }
                word[i] = w;
            }
        }

        if(level.find(endWord) != level.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, beginWord, level, seq, ans);
        }
        
        return ans;
    }
};