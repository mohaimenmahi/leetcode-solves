class UnionFind {
public:
    vector<int> parent, rank;
    UnionFind(int n) {
        for(int i = 0; i <= n; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    int findParent(int node) {
        int p = parent[node];
        
        while(p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }

        parent[node] = p;
        return p;
    }

    bool makeUnion(int u, int v) {
        int p1 = findParent(u);
        int p2 = findParent(v);

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
    int minScore(int n, vector<vector<int>>& roads) {
        UnionFind* uf = new UnionFind(n);

        for(auto road:roads) {
            int u = road[0];
            int v = road[1];
            uf->makeUnion(u, v);
        }

        int srcP = uf->findParent(1);

        int ans = INT_MAX;

        for(auto road:roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];
            int up = uf->findParent(u);
            int vp = uf->findParent(v);

            if(up == srcP && vp == srcP) {
                ans = min(ans, w);
            }
        }

        return ans;
    }
};