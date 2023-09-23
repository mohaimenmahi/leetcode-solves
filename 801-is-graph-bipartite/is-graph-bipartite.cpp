class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node) {
        for(int i = 0; i < graph[node].size(); i++) {
            int v = graph[node][i];

            if(color[v] == -1) {
                color[v] = 1 - color[node];
                if(!dfs(graph, color, v)) return false;
            } else if(color[node] == color[v]) return false;
        }

        return true;
    }
 public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                color[i] = 0;
                if(!dfs(graph, color, i)) return false;
            }
        }

        return true;
    }
};