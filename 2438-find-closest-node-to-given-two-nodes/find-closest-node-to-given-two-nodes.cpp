/* BFS Solution*/

class Solution {
private:
    vector<int> getDist(vector<vector<int>>& graph, int src, int n) {
        queue<int> q;
        vector<int> vis(n, 0);

        vector<int> dist(n, -1);

        dist[src] = 0;
        q.push(src);
        vis[src] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int v:graph[node]) {
                if(!vis[v]) {
                    dist[v] = dist[node] + 1;
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }

        return dist;
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<vector<int>> graph(n);

        for(int i = 0; i < n; i++) {
            if(edges[i] != -1) graph[i].push_back(edges[i]);
        }

        vector<int> dist1 = getDist(graph, node1, n);
        vector<int> dist2 = getDist(graph, node2, n);

        int idx = -1, maxVal = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(dist1[i] == -1 || dist2[i] == -1) continue;

            int maxIn = max(dist1[i], dist2[i]);

            if(maxIn < maxVal) {
                maxVal = maxIn;
                idx = i;
            }
        }

        return idx;
    }
};