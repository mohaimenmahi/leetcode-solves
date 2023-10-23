class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> graph(n);

        for(int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i+1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int w = abs(x1-x2) + abs(y1-y2);

                graph[i].push_back({j, w});
                graph[j].push_back({i, w});
            }
        }

        int sum = 0;
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;
        vector<int> vis(n, 0);

        pq.push({0, 0});

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int dist = top.first;
            int node = top.second;

            if(vis[node]) continue;

            vis[node] = 1;
            sum += dist;

            for(auto it:graph[node]) {
                int v = it.first;
                int w = it.second;

                if(!vis[v]) pq.push({w, v});
            }
        }

        return sum;
    }
};