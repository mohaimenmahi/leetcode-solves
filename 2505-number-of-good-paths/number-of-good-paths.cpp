class DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int n) {
        for(int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    int findUP(int node) {
        int p = parent[node];

        while(p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }

        parent[node] = p;
        return p;
    }

    void makeUnion(int u, int v) {
        int p1 = findUP(u);
        int p2 = findUP(v);

        if(p1 == p2) return;

        if(rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        DSU ds(n);

        map<int, vector<int>> mp;
        vector<vector<int>> graph(n);

        // storing the nodes mapping by it's value
        for(int i = 0; i < n; i++) {
            mp[vals[i]].push_back(i);
        }

        for(auto edge:edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int ans = n;

        for(auto it:mp) {
            int val = it.first; // the value
            vector<int> tmp = it.second; // nodes those have value val
            for(int node:tmp) {
                for(int v:graph[node]) {
                    // if the adjacent node value is greater then val, do not union
                    // because we can not go through this
                    if(val < vals[v]) continue; 
                    // otherwise, there can be a good path, make union
                    ds.makeUnion(node, v);
                }
            }
            // count the number of unique parents of nodes in the it->second
            // cnt[parent] = total count of parent = total nodes that has same parent
            unordered_map<int, int> cnt;
            for(int node:tmp) cnt[ds.findUP(node)]++;
            // if cnt[parent] > 1, that means, we can create a path
            // we need minimum two nodes to create path
            // so total path we can create nCr (n = cnt[parent], r = 2)
            for(auto c:cnt) {
                if(c.second > 1) {
                    ans += (c.second * (c.second - 1)) / 2;
                }
            }
        }

        return ans;
    }
};