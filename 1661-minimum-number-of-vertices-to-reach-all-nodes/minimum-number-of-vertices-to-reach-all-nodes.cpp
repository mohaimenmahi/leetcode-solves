class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& graph) {
        vis[node] = 1;

        for(int v:graph[node]) {
            if(!vis[v]) dfs(v, vis, graph);
        }
    }
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0), indegree(n, 0);
        vector<vector<int>> graph(n);

        for(auto edge:edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(!vis[i] && !indegree[i]) {
                dfs(i, vis, graph);
                ans.push_back(i);
            }
        }

        return ans;
    }
};