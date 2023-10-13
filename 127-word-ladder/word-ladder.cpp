class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& words) {
        set<string> st, vis;

        for(int i = 0; i < words.size(); i++) st.insert(words[i]);

        int len = beginWord.size();

        queue<string> q;
        q.push(beginWord);
        int level = 0;
        vis.insert(beginWord);

        while(!q.empty()) {
            int size = q.size();
            level++;

            for(int i = 0; i < size; i++) {
                string val = q.front();
                q.pop();

                if(val == endWord) return level;

                string str;
                for(int j = 0; j < len; j++) {
                    str = val;
                    for(int k = 0; k < 26; k++) {
                        if(val[j] == 'a' + k) continue;

                        str[j] = 'a' + k;
                        if(st.find(str) != st.end() && vis.find(str) == vis.end()) {
                            q.push(str);
                            vis.insert(str);
                        }
                    }
                }
            }
        }

        return 0;
    }
};