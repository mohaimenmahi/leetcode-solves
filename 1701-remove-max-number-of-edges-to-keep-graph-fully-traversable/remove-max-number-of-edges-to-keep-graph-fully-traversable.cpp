class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        for(int i = 0; i <= n; i++) {
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

    bool isFullTraversable() {
        int cnt = 0;
        for(int i = 1; i < parent.size(); i++) {
            if(i == findUP(i)) cnt++;
        }

        return cnt == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {        
        int cnt = 0;

        DSU alice(n);
        DSU bob(n);

        for(auto e:edges) {
            if(e[0] == 3) {
                if(alice.findUP(e[1]) == alice.findUP(e[2]) && 
                    bob.findUP(e[1]) == bob.findUP(e[2])
                ) {
                    cnt++;
                } else {
                    alice.makeUnion(e[1], e[2]);
                    bob.makeUnion(e[1], e[2]);
                }   
            }
        }

        for(auto e:edges) {
            if(e[0] == 1) {
                if(alice.findUP(e[1]) != alice.findUP(e[2])) {
                    alice.makeUnion(e[1], e[2]);
                } else cnt++;
            }
            if(e[0] == 2) {
                if(bob.findUP(e[1]) != bob.findUP(e[2])) {
                    bob.makeUnion(e[1], e[2]);
                } else cnt++;
            }
        }

        int isSame = alice.isFullTraversable() && bob.isFullTraversable();

        return isSame ? cnt : -1;
    }
};