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

    int countSize(int p) {
        return rank[p];
    }
};

class Solution {
private:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs(
        DSU* ds,
        int n, 
        int row, 
        int col, 
        vector<vector<int>>& vis, 
        vector<vector<int>>& grid
    ) {
        vis[row][col] = 1;
        int node = (row * n) + col;
        
        for(int i = 0; i < 4; i++) {
            int r = row + dx[i];
            int c = col + dy[i];

            if(r < 0 || c < 0 || r == n || c == n || vis[r][c] || !grid[r][c]) continue;

            int adNode = (r*n) + c;

            if(ds->findUP(node) != ds->findUP(adNode)) {
                ds->makeUnion(node, adNode);
            }
            dfs(ds, n, r, c, vis, grid);
        }
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        
        DSU* ds = new DSU(n*n);

        vector<vector<int>> vis(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && grid[i][j]) dfs(ds, n, i, j, vis, grid);
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && !grid[i][j]) {
                    vis[i][j] = 1;
                    int res = 1;
                    unordered_set<int> st;
                    for(int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];

                        if(x < 0 || y < 0 || x == n || y == n || !grid[x][y]) continue;

                        int node = (x * n) + y;
                        int p = ds->findUP(node);
                        if(st.count(p) == 0) {
                            res += ds->countSize(p);
                            st.insert(p);
                        }
                    }
                    ans = max(res, ans);
                }
            }
        }

        return ans > 0 ? ans : n*n;
    }
};