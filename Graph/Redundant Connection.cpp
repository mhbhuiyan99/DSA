Problem Link : https://leetcode.com/problems/redundant-connection/description/?envType=daily-question&envId=2025-01-29
Explanation : https://leetcode.com/problems/redundant-connection/solutions/1295887/easy-solution-w-explanation-all-possible-approaches-with-comments
>>>>> --------- DSU ---------- <<<<<

int find(int a, vector<int>& par)
    {
        if(a == par[a]) return a;
        return find(par[a], par);
    }
    bool Union(int a, int b, vector<int>& par)
    {
        int x = find(a, par);
        int y = find(b, par);

        if(x == y) return false;
        return par[x] = y;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> par(n+1);
        iota(par.begin(), par.end(),0);

        for(auto &E : edges)
        {
            if(Union(E[0], E[1], par) == false)
                return E;
        }
        return { };
    }

>>>>> --------- DFS ---------- <<<<<

bool dfs(int node, int par, vector<vector<int>> &v, vector<int>&vis)
    {
        vis[node] = 1;
        for(auto u : v[node])
        {
            if(!vis[u])
            {
                if(dfs(u, node, v, vis)) 
                    return true;
            }
            else if(u != par) 
                return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<vector<int>> v(n+1);

        for(int i=0; i<n; i++)
        {
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);

            vector<int> vis(n+1,0);
            if(dfs(edges[i][0], -1, v, vis))
                return edges[i];
        }
        return {};
    }
