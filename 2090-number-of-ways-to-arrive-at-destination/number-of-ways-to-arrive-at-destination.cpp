class Solution {
public:
    int mod = ((int) 1e9 + 7);
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        vector<vector<pair<int, int>>> graph(n);

        for(auto road:roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        vector<long long> time(n, 1e15);
        vector<int> ways(n, 0);

        pq.push({0, 0});
        time[0] = 0;
        ways[0] = 1;

        while(!pq.empty()) {
            long long t = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto v:graph[node]) {
                int x = v.first;
                long long xt = v.second;

                if(xt + t < time[x]) {
                    time[x] = xt + t;
                    pq.push({time[x], x});
                    ways[x] = ways[node];
                } else if(xt + t == time[x]) {
                    ways[x] = (ways[x] + ways[node]) % mod;
                }
            }
        }


        return ways[n-1] % mod;
    }
};