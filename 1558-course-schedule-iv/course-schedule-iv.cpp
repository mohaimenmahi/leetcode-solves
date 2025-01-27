class Solution {
public:
    vector<bool> checkIfPrerequisite(
        int numCourses, 
        vector<vector<int>>& prerequisites, 
        vector<vector<int>>& queries
    ) {
        vector<vector<int>> graph(numCourses);
        vector<int> indgr(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            indgr[v]++;
            graph[u].push_back(v);
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(indgr[i] == 0) q.push(i);
        }

        unordered_map<int, unordered_set<int>> nodePrereqs;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int i:graph[node]) {
                // nodePrereqs[i] => the prerequisites of i
                nodePrereqs[i].insert(node);

                // nodePrereqs[node] => the prerequisites of node
                for(int it:nodePrereqs[node]) {
                    // inserting all the prerequisites of node as prereqs of i
                    nodePrereqs[i].insert(it);
                } 

                indgr[i]--;

                if(indgr[i] == 0) {
                    q.push(i);
                }
            }
        }

        vector<bool> res(queries.size(), false);

        for(int i = 0; i < queries.size(); i++) {
            int u = queries[i][0], v = queries[i][1];

            if(nodePrereqs.find(v) != nodePrereqs.end() && nodePrereqs[v].find(u) != nodePrereqs[v].end()) 
                res[i] = true;
        }

        return res;
    }
};