class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);

        for(auto it:times) {
            graph[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;
        vector<int> dist(n+1, INT_MAX);

        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto x:graph[node]) {
                int v = x.first;
                int d = x.second;

                if(dis + d < dist[v]) {
                    dist[v] = dis + d;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans  = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) return -1;
            else ans = max(ans, dist[i]);
        }

        return ans;
    }
};