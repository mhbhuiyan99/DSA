Problem Link: https://www.geeksforgeeks.org/problems/chocolates-pickup/1

>>>  Memorization Approach

int calc(int i, int j1, int j2, int n, int m, vector<vector<int>>&grid, vector<vector<vector<int>>> &dp)
    {
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e9;
        if(i == n-1)
        {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int mx = -1;
        for(int p = -1; p < 2; p++)
        {
            for(int q = -1, ans = 0; q < 2; q++)
            {
                if(j1 == j2) ans = grid[i][j1] + calc(i+1, j1 + p, j2 + q, n, m, grid, dp);
                else ans = grid[i][j1] + grid[i][j2] + calc(i+1, j1 + p, j2 + q, n, m, grid, dp);
                mx = max(mx, ans);
            }
        }
        return dp[i][j1][j2] = mx;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));
        return calc(0,0,m-1,n,m,grid,dp);
    }
---------------------------------------------------------------------------------------------------
  
