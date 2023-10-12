class Solution {
private:
    unordered_set<string> vis;
    unordered_map<string, vector<string>> graph;

    void dfs(vector<string>& merged, string email) {
        vis.insert(email);

        for(auto node:graph[email]) {
            if(vis.find(node) == vis.end()) {
                dfs(merged, node);
            }
        }

        merged.push_back(email);
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        for(int i = 0; i < n; i++) {
            int size = accounts[i].size();
            string firstEmail = accounts[i][1];

            for(int j = 2; j < size; j++) {
                string email = accounts[i][j];

                graph[firstEmail].push_back(email);
                graph[email].push_back(firstEmail);
            }
        }

        vector<vector<string>> ans;

        for(auto account:accounts) {
            string name = account[0];

            string email = account[1];

            if(vis.find(email) == vis.end()) {
                vector<string> merged;
                merged.push_back(name);

                dfs(merged, email);
                
                sort(merged.begin()+1, merged.end());
                ans.push_back(merged);
            }

        }

        return ans;
    }
};