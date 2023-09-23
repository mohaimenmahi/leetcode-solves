class Solution {
private:
    bool bfs(vector<vector<int>>& graph, vector<int>& color, int node) {
        queue<int> q;

        q.push(node);
        color[node] = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                if(color[v] == -1) {
                    q.push(v);
                    color[v] = 1 - color[u];
                } else if(color[v] == color[u]) return false;
            }
        }

        return true;
    }
 public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                if(!bfs(graph, color, i)) return false;
            }
        }

        return true;
    }
};