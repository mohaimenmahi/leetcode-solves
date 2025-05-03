class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<char> dom(dominoes.begin(), dominoes.end());

        int n = dom.size();
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            if(dom[i] != '.') q.push({i, dom[i]});
        }

        while(!q.empty()) {
            auto [idx, d] = q.front();
            q.pop();

            if(d == 'L') {
                if(idx > 0 && dom[idx-1] == '.') {
                    dom[idx-1] = 'L';
                    q.push({idx-1, 'L'});
                }
            } else {
                if(idx + 1 < n && dom[idx+1] == '.') {
                    if(idx + 2 < n && dom[idx+2] == 'L') q.pop();
                    else {
                        dom[idx+1] = 'R';
                        q.push({idx+1, 'R'});
                    }
                }
            }
        }

        string res(dom.begin(), dom.end());

        return res;
    }
};