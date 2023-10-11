class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& safe) {
        if(safe[node] != -1) return safe[node];

        safe[node] = 0;

        for(int i = 0; i < graph[node].size(); i++) {
            int v = graph[node][i];
            if(!dfs(v, graph, safe)) {
                return safe[node];
            }
        }

        safe[node] = 1;
        return safe[node];
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> safe(n, -1), ans;

        for(int i = 0; i < n; i++) {
            if(dfs(i, graph, safe)) ans.push_back(i);
        }

        return ans;
    }
};