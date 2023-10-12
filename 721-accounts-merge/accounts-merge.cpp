/* union find */

class UnionFind {
public:
    vector<int> parent, rank;
    UnionFind(int n) {
        rank.resize(n, 1);
        for(int i = 0; i < n; i++) parent.push_back(i);
    }

    int find(int node) {
        int p = parent[node];
        
        while(p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }

        parent[node] = p;
        return p;
    }

    bool makeUnion(int u, int v) {
        int p1 = find(u);
        int p2 = find(v);

        if(p1 == p2) return false;

        if(rank[p1] >= rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }

        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        UnionFind* uf = new UnionFind(n);
        unordered_map<string, int> emailToAc; // email -> index of account

        for(int i = 0; i < n; i++) {
            int size = accounts[i].size();
            for(int j = 1; j < size; j++) {
                string email = accounts[i][j];

                // if this email does not exist in the map, add it to the map;
                if(emailToAc.find(email) == emailToAc.end()) emailToAc[email] = i;
                else {
                    // else make union to i and emailToAc[email]
                    uf->makeUnion(i, emailToAc[email]);
                }
            }
        }

        unordered_map<int, vector<string>> emailGroup;

        for(auto& it:emailToAc) {
            int p = uf->find(it.second);
            emailGroup[p].push_back(it.first);
        }

        vector<vector<string>> ans;

        for(auto& it:emailGroup) {
            int idx = it.first;
            vector<string> merged;
            merged.push_back(accounts[idx][0]);
            merged.insert(merged.begin()+1, it.second.begin(), it.second.end());

            sort(merged.begin()+1, merged.end());
            ans.push_back(merged);
        }

        return ans;
    }
};