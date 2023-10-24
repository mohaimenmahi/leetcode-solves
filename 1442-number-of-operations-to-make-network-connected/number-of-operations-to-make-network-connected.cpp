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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);

        int opt = 0;
        for(auto con:connections) {
            int u = con[0];
            int v = con[1];

            if(ds.findUP(u) != ds.findUP(v)) ds.makeUnion(u, v);
            else opt++;
        }

        int comp = 0;
        for(int i = 0; i < n; i++) {
            if(ds.findUP(i) == i) comp++;
        }
        
        int minCon = comp - 1;

        if(opt >= minCon) return minCon;
        
        return -1;
    }
};