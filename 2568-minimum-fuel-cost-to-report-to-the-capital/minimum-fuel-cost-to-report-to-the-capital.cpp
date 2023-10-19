class Solution {
private:
    long long ans = 0;
    int dfs(int node, int prev, int seats, vector<vector<int>>& graph) {
        int pass = 0;
        // pass = number of passengers coming to 'node'
        for(int v:graph[node]) {
            if(v != prev) {
                int p = dfs(v, node, seats, graph); 
                // p = number of passengers coming to 'v'
                pass += p;
                ans += (long long) ceil((double) p / seats);
                // ceil(p / seats) = number of cars needed to come 'v' taking 'p' passengers
            }
        }

        return pass + 1; // number of passengers going from 'node' to it's parent 
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();

        vector<vector<int>> graph(n+1);

        for(auto road:roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }

        dfs(0, -1, seats, graph);

        return ans;
    }
};