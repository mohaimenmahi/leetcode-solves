class Solution {
private:
    int dfs(int node, unordered_set<int>& vis, vector<vector<int>>& graph) {
        if(vis.count(node) > 0) return 0;
        
        vis.insert(node);
        for(int v:graph[node]) {
            if(vis.count(v) == 0) dfs(v, vis, graph);
        }

        int res = vis.size();

        return res;
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);

        for(int i = 0; i < n; i++) {
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            int r1 = bombs[i][2];
            for(int j = i+1; j < n; j++) {
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                int r2 = bombs[j][2];

                double d = (double) sqrt(pow((x1-x2), 2) + pow((y1-y2),2));
                if((double) r1 >= d) {
                    graph[i].push_back(j);
                }
                if((double) r2 >= d) {
                    graph[j].push_back(i);
                }
            }
        }

        int res = 0;

        for(int i = 0; i < n; i++) {
            unordered_set<int> vis;
            res = max(dfs(i, vis, graph), res);
        }

        return res;
    }
};