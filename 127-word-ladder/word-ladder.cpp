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
                string val = q.front();
                q.pop();

                if(val == endWord) return level;
                st.erase(val); // we are just removing the popped word. That works like vis

                string str;
                for(int j = 0; j < len; j++) {
                    str = val;
                    for(int k = 0; k < 26; k++) {
                        if(val[j] == 'a' + k) continue;

                        str[j] = 'a' + k;
                        if(st.find(str) != st.end()) {
                            q.push(str);
                        }
                    }
                }
            }
        }

        return 0;
    }
};