class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& preqs) {
        vector<int> indegree(num, 0), ans;
        vector<vector<int>> graph(num);

        queue<int> q;

        for(int i = 0; i < preqs.size(); i++) {
            int u = preqs[i][1];
            int v = preqs[i][0];

            graph[u].push_back(v);
            indegree[v]++;
        }

        for(int i = 0; i < num; i++) {
            if(!indegree[i]) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int i = 0; i < graph[node].size(); i++) {
                int v = graph[node][i];

                if(indegree[v]) indegree[v]--;
                
                if(indegree[v] == 0) q.push(v);
            }
        }

        if(ans.size() != num) return {};

        return ans;
    }
};