class Solution {
private:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool inValid(int row, int col, int n, int m) {
        return row < 0 || col < 0 || row == n || col == m;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int d = top.first;
            int row = top.second.first;
            int col = top.second.second;
            
            for(int i = 0; i < 4; i++) {
                int x = row + dx[i];
                int y = col + dy[i];
                
                if(inValid(x, y, n, m)) continue;
                
                int diff = max(abs(heights[x][y] - heights[row][col]), d);
                
                if(diff < dist[x][y]) {
                    dist[x][y] = diff;
                    pq.push({dist[x][y], {x, y}});
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};