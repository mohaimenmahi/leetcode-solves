class Solution {
private:
    bool dfs(
        int node, 
        vector<int>& vis, 
        vector<vector<int>>& graph
    ) {
        vis[node] = 1;

        for(int child:graph[node]) {
            if(!vis[child]) {
                if(!dfs(child, vis, graph)) return false;
            } else if(vis[child] == 1) return false;
        }

        vis[node] = 2;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs(i, vis, graph);
        }

        vector<int> res;

        for(int i = 0; i < n; i++) {
            if(vis[i] == 2) res.push_back(i);
        }

        return res;
    }
};