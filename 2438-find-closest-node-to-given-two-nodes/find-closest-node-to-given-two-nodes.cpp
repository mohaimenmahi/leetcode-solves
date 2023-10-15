/* BFS Solution*/

class Solution {
private:
    vector<int> getDist(vector<vector<int>>& graph, int src, int n) {
        queue<int> q;

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        q.push(src);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto v:graph[node]) {
                if(dist[node] + 1 < dist[v]) {
                    dist[v] = dist[node] + 1;
                    q.push(v);
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
            if(dist1[i] == INT_MAX || dist2[i] == INT_MAX) continue;

            int maxIn = max(dist1[i], dist2[i]);

            if(maxIn < maxVal) {
                maxVal = maxIn;
                idx = i;
            }
        }

        return idx;
    }
};