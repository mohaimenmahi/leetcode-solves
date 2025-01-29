class UnionFind {
private:
    int n;
    vector<int> parent, rank;
public:
    UnionFind(int nodes) {
        n = nodes;
        for(int i = 0; i <= n; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    int findParent(int node) {
        int par = parent[node];

        while(par != parent[par]) {
            parent[par] = parent[parent[par]];
            par = parent[par];
        }

        parent[node] = par;
        return par;
    }

    void makePair(int u, int v) {
        int up = findParent(u);
        int vp = findParent(v);

        if(up == vp) return;

        if(rank[up] > rank[vp]) {
            rank[up] += rank[vp];
            parent[vp] = up;
        } else {
            rank[vp] += rank[up];
            parent[up] = vp;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        UnionFind uf(n);

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int u = edges[i][0], v = edges[i][1];

            int up = uf.findParent(u), vp = uf.findParent(v);

            if(up != vp) uf.makePair(u, v);
            else ans = {u, v};
        }

        return ans;
    }
};