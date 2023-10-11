class Solution {
private:
    int find(int node, vector<int>& parent, vector<int>& rank) {
        int p = parent[node];

        while(p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }

        parent[node] = p;
        return p;
    }

    bool makeUnion(int n1, int n2, vector<int>& parent, vector<int>& rank) {
        int p1 = find(n1, parent, rank);
        int p2 = find(n2, parent, rank);

        if(p1 == p2) return false;
        else if(rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }

        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> parent(n+1, 0), rank(n+1, 1);

        for(int i = 0; i <= n; i++) parent[i] = i;

        for(int i = 0; i < n; i++) {
            if(!makeUnion(edges[i][0], edges[i][1], parent, rank)) return edges[i];
        }

        return {};
    }
};