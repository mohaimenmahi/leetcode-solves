class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& path) {
        vis[node] = 1;
        path[node] = 1;

        for(int i = 0; i < graph[node].size(); i++) {
            int v = graph[node][i];

            if(!vis[v]) {
                if(dfs(v, graph, vis, path)) return true;
            } else if(path[v]) return true;
        }

        path[node] = 0;

        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n, 0), path(n, 0), ans;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs(i, graph, vis, path);
        }

        for(int i = 0; i < n; i++) {
            if(path[i] == 0) ans.push_back(i);
        }

        return ans;
    }
};