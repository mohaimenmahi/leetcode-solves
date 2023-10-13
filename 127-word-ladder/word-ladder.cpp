class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& words) {
        unordered_set<string> st;

        for(int i = 0; i < words.size(); i++) st.insert(words[i]);

        int len = beginWord.size();

        queue<string> q;
        q.push(beginWord);
        int level = 0;

        while(!q.empty()) {
            int size = q.size();
            level++;

            for(int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                if(word == endWord) return level;
                st.erase(word); // we are just removing the popped word. That works like vis

                for(int j = 0; j < len; j++) {
                    char c = word[j];
                    for(int k = 0; k < 26; k++) {
                        if(word[j] == 'a' + k) continue;

                        word[j] = 'a' + k;
                        if(st.find(word) != st.end()) {
                            q.push(word);
                        }
                    }
                    word[j] = c;
                }
            }
        }

        return 0;
    }
};