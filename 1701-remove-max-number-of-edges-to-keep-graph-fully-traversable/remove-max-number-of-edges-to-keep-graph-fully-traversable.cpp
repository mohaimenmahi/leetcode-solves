class DSU {
private:
    vector<int> parent, rank;
    int nodes;
public:    
    DSU(int n) {
        nodes = n;
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

    int makeUnion(int u, int v) {
        int p1 = findUP(u);
        int p2 = findUP(v);

        if(p1 == p2) return 0;

        if(rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        nodes -= 1;
        return 1;
    } 

    bool isFullConnected() {
        return nodes == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {        
        int cnt = 0; // number of connections we need

        DSU alice(n);
        DSU bob(n);

        for(auto e:edges) {
            if(e[0] == 3) {
                cnt += (alice.makeUnion(e[1], e[2]) | bob.makeUnion(e[1], e[2]));
            }
        }

        for(auto e:edges) {
            if(e[0] == 1) {
                cnt += alice.makeUnion(e[1], e[2]);
            }

            if(e[0] == 2) {
                cnt += bob.makeUnion(e[1], e[2]);
            }
        }

        if(alice.isFullConnected() && bob.isFullConnected())
            return edges.size() - cnt;

        return -1;
    }
};