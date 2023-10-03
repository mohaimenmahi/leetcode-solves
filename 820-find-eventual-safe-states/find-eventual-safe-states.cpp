/* Topological sort solution */
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indg(n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                int u = graph[i][j];
                adj[u].push_back(i);
                indg[i]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(!indg[i]) q.push(i);
        }

        vector<int> ans;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int i = 0; i < adj[node].size(); i++) {
                int v = adj[node][i];

                if(indg[v]) indg[v]--;
                if(!indg[v]) q.push(v);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};