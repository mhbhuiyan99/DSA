Problem link: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
class Solution{
    public:
    
    int dx[4] = {1, 0, 0,-1};
    int dy[4] = {0,-1, 1, 0};
    char c[4] = {'D','L','R','U'};
    
    void path(int i, int j, int n, string s, vector<string> &ans, vector<vector<int>> &m, vector<vector<int>> &vis)
    {
        for(int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            
            if(i == n-1 and j == n-1)
            {
                ans.push_back(s);
                return;
            }
            
            if(x >= 0 and x < n and y >= 0 and y < n)
            {
                if(vis[x][y] == 0 and m[x][y] == 1)
                {
                    vis[i][j] = 1;
                    path(x,y,n,s+c[k],ans,m,vis);
                    vis[i][j] = 0;
                }
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n,0));
        if(m[0][0] == 1)
            path(0, 0, n, "", ans, m, vis);
        return ans;
    }
};
