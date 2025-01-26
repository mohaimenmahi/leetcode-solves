class Solution {
private:
    int bfs(int start, vector<vector<int>>& graph, unordered_set<int>& vis) {
        queue<pair<int, int>> q;

        q.push({start, 0});
        int maxLevel = 0;

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            int depth = front.second, node = front.first;
            maxLevel = max(maxLevel, depth);

            for(int child:graph[node]) {
                if(!vis.count(child)) {
                    vis.insert(child);
                    q.push({child, depth+1});
                }
            }
        }

        return maxLevel;        
    }

    void dfs(
        int node, 
        vector<int>& vis, 
        vector<vector<int>>& graph, 
        vector<vector<int>>& reverseGraph, 
        int dist,
        int& maxLen, 
        int& maxForTwo, 
        unordered_map<int, int>& distMap
    ) {
        vis[node] = 1;
        distMap[node] = dist;
        dist++;
        for(int child : graph[node]) {
            if(!vis[child]) {
                dfs(child, vis, graph, reverseGraph, dist, maxLen, maxForTwo, distMap);
            } else if(vis[child] == 1) {
                int cycleLen = dist - distMap[child];
                if(cycleLen == 2) {
                    unordered_set<int> cycleVis;
                    cycleVis.insert(node);
                    cycleVis.insert(child);
                    maxForTwo += 2 + bfs(node, reverseGraph, cycleVis) + bfs(child, reverseGraph, cycleVis);
                }
                maxLen = max(maxLen, cycleLen);
            }
        }

        vis[node] = 2;
    }
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();

        vector<vector<int>> graph(n);
        vector<vector<int>> reverseGraph(n);

        // taking the graph in reverse order
        for(int i = 0; i < n; i++) {
            int person = favorite[i];
            graph[i].push_back(person);
            reverseGraph[person].push_back(i);
        }

        int maxLen = 0, maxForTwo = 0;

        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                unordered_map<int, int> distMap;
                dfs(i, vis, graph, reverseGraph, 0, maxLen, maxForTwo, distMap);
            }
        }

        return max(maxLen, maxForTwo);
    }   
};