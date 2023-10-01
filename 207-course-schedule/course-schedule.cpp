class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for(int i = 0; i < prerequisites.size(); i++) {
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            indegree[v]++;
            graph[u].push_back(v);
        }

        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(!indegree[i]) q.push(i);
        }

        int completed = 0;

        while(!q.empty()) {
            int node = q.front();
            completed++;
            q.pop();

            for(int i = 0; i < graph[node].size(); i++) {
                int v = graph[node][i];
                if(indegree[v]) indegree[v]--;

                if(!indegree[v]) q.push(v);
            }
        }

        return completed == n;
    }
};