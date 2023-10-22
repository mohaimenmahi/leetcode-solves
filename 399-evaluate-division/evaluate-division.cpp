class Solution {
private:
    void dfs(
        string start,
        string node, 
        string prev,
        string end, 
        unordered_map<string, vector<pair<string, double>>>& graph,
        map<pair<string, string>, double>& divisions,
        double mult
    ) {
        if(node == end) return;

        for(auto it:graph[node]) {
            string v = it.first;
            double val = it.second;

            if(v != prev && v != start) {
                divisions[{start, v}] = mult * val;
                dfs(start, v, node, end, graph, divisions, mult * val);
            }
        }
    }
public:
    vector<double> calcEquation(
        vector<vector<string>>& equations, 
        vector<double>& values, 
        vector<vector<string>>& queries
    ) {
        unordered_map<
            string, 
            vector<pair<string, double>>
        > graph;
        map<pair<string, string>, double> divisions;

        int n = equations.size();
        unordered_set<string> st;

        for(int i = 0; i < n; i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b, (double) val});
            graph[b].push_back({a, (double) (1.0 / val)});
            st.insert(a);
            st.insert(b);
        }

        vector<double> ans(queries.size(), -1.0000);

        for(int i = 0; i < queries.size(); i++) {
            string a = queries[i][0];
            string b = queries[i][1];

            if(a == b) divisions[{a, b}] = 1.000;
            else divisions[{a, b}] = -1.000;

            if(st.count(a) > 0 && st.count(b) > 0) {
                dfs(a, a, "", b, graph, divisions, 1.00);
                ans[i] = divisions[{a, b}];
            }
        }

        return ans;
    }
};