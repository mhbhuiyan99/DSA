Problem Link : https://leetcode.com/problems/course-schedule/description/

>>>> ----- DFS ------- <<<<

class Solution {
public:

    bool dfs(vector<vector<int>> &v, vector<int> &vis, vector<int> &curVis, int node, int par)
    {
        vis[node] = 1;
        curVis[node] = 1;

        for(auto u : v[node])
        {
            if(vis[u] == 0)
            {
                if(dfs(v, vis, curVis, u, node) == true)
                    return true;
            }
            else if(curVis[u]) return true;
        }
        curVis[node] = 0;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>> v(n);
        vector<int> vis(n,0), curVis(n,0);

        for(int i=0; i<pre.size(); i++)
        {
            int x = pre[i][0], y = pre[i][1];

            v[x].push_back(y);
        }

        for(int i=0; i<n; i++)
        {
            if(vis[i] == 0)
            {
                if(dfs(v, vis, curVis, i, -1))
                    return false;
            }
        }
    return true;
    }
};
