class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n, 
        vector<vector<int>>& redEdges, 
        vector<vector<int>>& blueEdges
    ) {
        vector<vector<int>> red(n), blue(n);
        set<pair<int, int>> vis;

        for(auto edge:redEdges) {
            red[edge[0]].push_back(edge[1]);
        }

        for(auto edge:blueEdges) {
            blue[edge[0]].push_back(edge[1]);
        }

        vector<int> ans(n, -1);

        queue<pair<int, int>> q;
        q.push({0, -1});  
        vis.insert({0, -1});
        int level = 0;

        // taking 0 red, 1 as blue

        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();

                int u = node.first;
                int col = node.second;

                // -1 means node u is first time visited, and while first time, 
                // this is the lowest value
                if(ans[u] == -1) ans[u] = level;

                // we are not storing the later distances
                // just running and tracking the traversal 
                if(col != 1) {
                    for(int v:red[u]) {
                        if(vis.count({v, 1})) continue;
                        
                        q.push({v, 1});
                        vis.insert({v, 1});
                    }
                }
                if(col != 0) {
                    for(int v:blue[u]) {
                        if(vis.count({v, 0})) continue;
                        
                        q.push({v, 0});
                        vis.insert({v, 0});
                    }
                }
            }
            level++;
        }

        return ans;
    }
};