// advanced TopoSort

class Solution {
private:
    void dfs(
        string node, 
        unordered_map<string, multiset<string>>& graph,
        vector<string>& ans
    ) {
        // checking if the graph is not empty
        // that means there is a way to go to next airport

        // if graph[node] is empty, we will not move to the next
        // skipping the while loop just push it to the ans
        while(!graph[node].empty()) {
            string next = *graph[node].begin();
            // removing the node's current occurence from the list
            graph[node].erase(graph[node].begin());
            // as we are starting from the begin() and removing it
            // the next will always be in the begin() position
            dfs(next, graph, ans);
        }

        // when dfs of the node is finished, push it to the ans
        // for nodes that does not have next node, the while loop will not executed
        // so direct come to that step and store it
        ans.push_back(node);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        // taking multiset because there may be same node multiple times
        // let say ["JFK", "SFO"], ["JFK", "SFO"]
        // will take both as graph["JFK"] = ("SFO", "SFO")

        for(auto ticket:tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }

        vector<string> ans;
        dfs("JFK", graph, ans);
        // as we are inserting into ans after traversal completion, reverse it
        reverse(ans.begin(), ans.end());
        return ans;
    }
};