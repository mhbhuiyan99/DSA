// Problem Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        
        vector<int> adj[V];
        
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        

        queue<pair<int,int>> q;
        q.push({src, 0});
        
        vector<int> vis(V, 0);
        vis[src] = 1;
        
        vector<int> ans(V, -1);
        
        while(!q.empty()) {
            int node = q.front().first;
            int dis = q.front().second;
            
            q.pop();
            ans[node] = dis;
            
            for(auto &u : adj[node]) {
                if(!vis[u]) {
                    vis[u] = 1;
                    q.push({u, dis + 1});
                }
            }
        }
        
        return ans;
    }
};
