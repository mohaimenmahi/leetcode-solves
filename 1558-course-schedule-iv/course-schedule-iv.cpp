class Solution {
private:
    unordered_set<int> dfs(
        int node, 
        vector<vector<int>>& graph, 
        unordered_map<int, unordered_set<int>>& mp
    ) {
        if(mp.find(node) == mp.end()) {
            for(int i = 0; i < graph[node].size(); i++) {
                int v = graph[node][i];
                mp[node].insert(v);
                unordered_set<int> st = dfs(v, graph, mp);
                for(auto it:st) mp[node].insert(it);
            }
        }

        return mp[node];
    }
public:
    vector<bool> checkIfPrerequisite(
        int num, 
        vector<vector<int>>& preqs, 
        vector<vector<int>>& qrs
    ) {
        vector<vector<int>> graph(num);

        unordered_map<int, unordered_set<int>> mp;
        // mp[node] -> hashset of all the prerequisites

        for(int i = 0; i < preqs.size(); i++) {
            // for [a, b], we are taking b -> a manner, so that we can keep track
            // of the prerequisites of b in a hashset
            int u = preqs[i][1]; 
            int v = preqs[i][0];
            graph[u].push_back(v);
        }

        for(int i = 0; i < num; i++) dfs(i, graph, mp);

        vector<bool> ans(qrs.size(), false);

        for(int i = 0; i < qrs.size(); i++) {
            int a = qrs[i][0];
            int b = qrs[i][1];
            if(mp.find(b) != mp.end() && mp[b].find(a) != mp[b].end()) ans[i] = true;
        }

        return ans;
    }
};