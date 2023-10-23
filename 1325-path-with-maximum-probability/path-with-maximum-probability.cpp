class Solution {
public:
    double maxProbability(
        int n, 
        vector<vector<int>>& edges, 
        vector<double>& succProb, 
        int start_node, 
        int end_node
    ) {
        vector<vector<pair<int, double>>> graph(n);
        int e = edges.size();

        for(int i = 0; i < e; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            graph[u].push_back({v, p});
            graph[v].push_back({u, p});
        }

        priority_queue<
            pair<double, int>
        > pq;
        vector<double> maxProb(n, 0.00000);

        pq.push({1.00000, start_node}); 
        maxProb[start_node] = 1.00000;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            double prob = top.first;
            int node = top.second;

            for(auto it:graph[node]) {
                int v = it.first;
                double p = it.second;

                if((double) p * prob > maxProb[v]) {
                    maxProb[v] = p * prob;
                    pq.push({maxProb[v], v});
                }
            }
        }

        return maxProb[end_node];
    } 
};