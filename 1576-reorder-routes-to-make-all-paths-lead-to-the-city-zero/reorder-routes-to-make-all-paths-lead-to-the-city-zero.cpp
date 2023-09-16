class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_set<int> vis;
        unordered_map<int, vector<int>> graph;
        set<pair<int, int>> edges;

        for(int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            edges.insert({ u, v });
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<int> q;

        vis.insert(0);
        q.push(0);

        int ans = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int i = 0; i < graph[node].size(); i++) {
                int uv = graph[node][i];

                if(vis.count(uv)) continue;
                if(!edges.count({uv, node})) ans++;
                vis.insert(uv);
                q.push(uv);
            }
        }

        return ans;
    }
};