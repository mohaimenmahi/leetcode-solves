class Solution {
public:
    vector<bool> checkIfPrerequisite(
        int num, 
        vector<vector<int>>& preqs, 
        vector<vector<int>>& qrs
    ) {
        vector<vector<bool>> hasPath(num, vector<bool>(num, false));

        for(int i = 0; i < preqs.size(); i++) {
            int u = preqs[i][0], v = preqs[i][1];
            hasPath[u][v] = true; // means from u to v, there is a path
        }

        for(int k = 0; k < num; k++) {
            for(int i = 0; i < num; i++) {
                for(int j = 0; j < num; j++) {
                    hasPath[i][j] = hasPath[i][j] || (hasPath[i][k] && hasPath[k][j]);
                }
            }
        }

        vector<bool> res;

        for(int i = 0; i < qrs.size(); i++) {
            int u = qrs[i][0], v = qrs[i][1];

            res.push_back(hasPath[u][v]);
        }

        return res;
    }
};