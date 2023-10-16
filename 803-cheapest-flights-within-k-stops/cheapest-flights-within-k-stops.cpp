class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);

        for(auto flight:flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> cost(n, INT_MAX);

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); // {stops , {node, price}}

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            int stops = front.first;
            int node = front.second.first;
            int price = front.second.second;

            if(stops == k + 1) break;
            if(node == dst) continue;

            for(auto it:graph[node]) {
                int v = it.first;
                int p = it.second;

                if(p + price < cost[v]) {
                    cost[v] = p + price;
                    q.push({stops + 1, {v, cost[v]}});
                }
            }
        }

        if(cost[dst] == INT_MAX) return -1;
        return cost[dst];
    }
};