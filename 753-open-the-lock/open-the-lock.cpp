class Solution {
private:
    vector<string> children(string lock) {
        vector<string> res;

        for(int i = 0; i < 4; i++) {
            string s1 = lock, s2 = lock;
            s1[i] = (((lock[i] - '0') + 1) % 10) + '0';
            s2[i]= ((((lock[i]-'0') - 1) + 10) % 10) + '0';
            res.push_back(s1);
            res.push_back(s2);
        }

        return res;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> vis;

        for(int i = 0; i < deadends.size(); i++) vis.insert(deadends[i]);

        if(vis.find("0000") != vis.end()) return -1;

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        vis.insert("0000");

        while(!q.empty()) {
            string lock = q.front().first;
            int moves = q.front().second;
            q.pop();

            if(lock == target) return moves;

            vector<string> child = children(lock);

            for(int i = 0; i < child.size(); i++) {
                if(vis.find(child[i]) == vis.end()) {
                    vis.insert(child[i]);
                    q.push({child[i], moves + 1});
                }
            }
        }

        return -1;
    }
};