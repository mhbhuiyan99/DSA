Problem Link : https://leetcode.com/problems/unique-paths-ii/description/

>>>  Memorization Approach

int solve(vector<vector<int>> &v, int i, int j, vector<vector<int>> &dp)
    {
        if(dp[i][j] != -1) return dp[i][j];
        if(i == 0 and j == 0 and v[i][j] == 0) return dp[i][j] = 1;
        if(v[i][j] == 1) return dp[i][j] = 0;

        int up = 0;
        if(i>0) up = solve(v,i-1,j,dp);
        int left = 0;
        if(j>0) left = solve(v,i,j-1,dp);

        return dp[i][j] = up + left;
    }
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return solve(obstacleGrid, m-1, n-1, dp);
    }
---------------------------------------------------------------------------------

>>>  Tabulation Approach

int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 and j == 0) dp[i][j] = 1;
                else if(v[i][j] == 0)
                {
                    int up = 0, left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
---------------------------------------------------------------------------------

>>>  Space Optimization Approach

int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<int> pre(n,0);
        
        for(int i=0; i<m; i++)
        {
            vector<int> tmp(n,0);
            for(int j=0; j<n; j++)
            {
                if(v[i][j] == 1) tmp[j] = 0;
                else if(i == 0 and j == 0) tmp[j] = 1;
                else if(v[i][j] == 0)
                {
                    int up = 0, left = 0;
                    if(i > 0) up = pre[j];
                    if(j > 0) left = tmp[j-1];
                    tmp[j] = up + left;
                }
            }
            pre = tmp;
        }
        return pre[n-1];
    }



