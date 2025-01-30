Problem Link : https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/
Approach : https://youtu.be/MSG7qX_UiKQ?si=eKgmdtaJUuDHpZVV

class Solution
{
public:
    int bfs(vector<vector<int>> &adj, int curr, int n)
    {
        vector<bool> vis(n + 1, 0);

        queue<int> q;
        q.push(curr);
        vis[curr] = 1;

        int cnt = 0;
        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                int node = q.front();
                q.pop();

                for (auto nxt : adj[node])
                {
                    if (vis[nxt] == 0)
                    {
                        q.push(nxt);
                        vis[nxt] = 1;
                    }
                }
            }
            cnt++;
        }


        return cnt;
    }

    int maxDist(vector<vector<int>> &adj, int curr, vector<int> &vis, vector<int> &dist)
    {
        if (vis[curr])
            return dist[curr];

        vis[curr] = 1;
        int ma = dist[curr];
        for (auto nxt : adj[curr])
        {
            ma = max(ma, maxDist(adj, nxt, vis, dist));
        }

        return ma;
    }
    int getMaxGroupCount(vector<vector<int>> &adj, int n)
    {
        vector<int> dist(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            dist[i] = (bfs(adj, i, n));
        }

        int ma = 0;
        vector<int> vis(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                ma += maxDist(adj, i, vis, dist);
            }
        }
        return ma;
    }
    void isValid(vector<vector<int>> &adj, vector<int> &vis, int curr, bool &flag, int val)
    {
        if (vis[curr] != -1)
        {
            flag &= (val == vis[curr]);
            return;
        }

        vis[curr] = val;
        for (auto nxt : adj[curr])
        {
            isValid(adj, vis, nxt, flag, 1 - val);
        }

        return;
    }
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n + 1);

        for (auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> vis(n + 1, -1);
        bool flag = true;

        for (int i = 1; i <= n; i++)
        {
            if (flag and vis[i] == -1)
                isValid(adj, vis, i, flag, 1);
        }

        if (!flag)
            return -1;

        return getMaxGroupCount(adj, n);
    }
};
