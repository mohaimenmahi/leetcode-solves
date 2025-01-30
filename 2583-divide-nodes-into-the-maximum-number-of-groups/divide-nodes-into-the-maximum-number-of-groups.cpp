class Solution {
private:
    bool isGraphBipartite(int node, vector<int>& color, vector<vector<int>>& graph) {
        for(int child:graph[node]) {
            if(color[child] == color[node]) return false;

            if(color[child] != -1) continue;
            
            color[child] = 1 - color[node];
            if(!isGraphBipartite(child, color, graph)) return false;
        }
        return true;
    }

    int findMaxLevel(int src, vector<vector<int>>& graph) {
        unordered_set<int> vis;

        queue<pair<int, int>> q;

        q.push({1, src});
        vis.insert(src);

        int maxLevel = 0;

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            int node = front.second, dist = front.first;

            maxLevel = max(dist, maxLevel);

            for(int child:graph[node]) {
                if(!vis.count(child)) {
                    vis.insert(child);
                    q.push({dist+1, child});
                }
            }
        }

        return maxLevel;
    }

    // maximum depth found from this dfs = maximum number of groups can be found from that component
    int findGroups(int node, vector<int>& dist, vector<int>& vis, vector<vector<int>>& graph) {
        int maxDepth = dist[node];
        for(int child:graph[node]) {
            if(!vis[child]) {
                vis[child] = 1;
                maxDepth = max(maxDepth, findGroups(child, dist, vis, graph));
            }
        }

        return maxDepth;
    }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n+1);

        for(auto ed:edges) {
            graph[ed[0]].push_back(ed[1]);
            graph[ed[1]].push_back(ed[0]);
        }

        vector<int> color(n+1, -1);
        for(int i = 1; i <= n; i++) {
            if(color[i] == -1) {
                color[i] = 0;
                if(!isGraphBipartite(i, color, graph)) return -1;
            }
        }

        vector<int> dist(n+1, 0);

        for(int i = 1; i <= n; i++) {
            dist[i] = findMaxLevel(i, graph);
        }

        vector<int> vis(n+1, 0);

        int res = 0;
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                res += findGroups(i, dist, vis, graph);
            }
        }

        return res;
    }
};