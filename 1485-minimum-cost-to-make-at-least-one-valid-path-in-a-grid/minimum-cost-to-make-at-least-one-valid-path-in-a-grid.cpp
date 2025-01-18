class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        vector<vector<int>> cost(rows, vector<int>(cols, INT_MAX));

        cost[0][0] = 0;

        while(true) {
            // copy the prevCost
            vector<vector<int>> prevCost = cost;

            // forward pass
            for(int row = 0; row < rows; row++) {
                for(int col = 0; col < cols; col++) {
                    if(row > 0) {
                        // coming from the top neighbor
                        cost[row][col] = min(
                            cost[row][col],
                            cost[row-1][col] + (
                                grid[row-1][col] == 3 ? 0 : 1
                            )
                        );
                    }

                    if(col > 0) {
                        // coming from the left neighbor
                        cost[row][col]= min(
                            cost[row][col], 
                            cost[row][col-1] + (
                                grid[row][col-1] == 1 ? 0 : 1
                            )
                        );
                    }
                }
            }

            // backward pass
            for(int row = rows-1; row >= 0; row--) {
                for(int col = cols-1; col >= 0; col--) {
                    // from down neighbor
                    if(row < rows-1) {
                        cost[row][col] = min(
                            cost[row][col],
                            cost[row+1][col] + (
                                grid[row+1][col] == 4 ? 0 : 1
                            )
                        );
                    }

                    // from right neighbor
                    if(col < cols-1) {
                        cost[row][col] = min(
                            cost[row][col],
                            cost[row][col+1] + (
                                grid[row][col+1] == 2 ? 0 : 1
                            )
                        );
                    }
                }
            }

            // if the prevCost has not changed in this iteration
            // that means, in each pass and each cell check from 
            // all for directions, the values has not been changed
            // in the cells from the previous iteration
            // that means we reached to the optimal cost

            if(prevCost == cost) break;
        }

        return cost[rows-1][cols-1];
    }
};