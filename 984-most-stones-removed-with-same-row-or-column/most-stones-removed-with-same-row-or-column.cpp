class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        for(int i = 0; i < n; i++) {
            rank.push_back(1);
            parent.push_back(i);
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

        if(rank[p1] >= rank[p2]) {
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU ds(n);
        vector<vector<int>> edges;

        for(int i = 0; i < n; i++) {
            int x = stones[i][0];
            int y = stones[i][1];

            for(int j = i+1; j < n; j++) {
                int xx = stones[j][0];
                int yy = stones[j][1];

                if(x == xx || y == yy) {
                    edges.push_back({i, j});
                }
            }
        }

        for(auto e:edges) {
            int u = e[0];
            int v = e[1];

            ds.makeUnion(u, v);
        }

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if(ds.findUP(i) == i) cnt++;
        }

        return n - cnt;
    }
};