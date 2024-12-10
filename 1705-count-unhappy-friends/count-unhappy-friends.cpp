class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& prefs, vector<vector<int>>& pairs) {
        vector<vector<int>> rank(n, vector<int>(n, 0));
        vector<int> conn(n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < prefs[i].size(); j++) {
                rank[i][prefs[i][j]] = j;
            }
        }

        for(int i = 0; i < pairs.size(); i++) {
            conn[pairs[i][0]] = pairs[i][1];
            conn[pairs[i][1]] = pairs[i][0];
        }

        int res = 0;

        for(int x = 0; x < conn.size(); x++) {
            int y = conn[x];

            for(int i = 0; i < prefs[x].size(); i++) {
                int u = prefs[x][i];
                int v = conn[u];

                if(rank[x][u] < rank[x][y] && rank[u][x] < rank[u][v]) {
                    res++;
                    break;
                }
            }
        }

        return res;
    }
};