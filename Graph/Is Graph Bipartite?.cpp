// Problem link: https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool dfs(int node, int n, vector<vector<int>>&graph, int c, vector<int> &col) {
        col[node] = c;

        for(auto u : graph[node]) {
    
            if(col[u] == -1) {
                if (!dfs(u, n, graph, c^1, col)) {
                    return false;
                }
            }
            
            if (col[node] == col[u]) 
                return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1);

        for(int i = 0; i < n; i++) {
            if (col[i] == -1) {
                if (!dfs(i, n, graph, 0, col)) 
                    return false;
            }
        }
        return true;
    }
};
