Problem Link: https://leetcode.com/problems/triangle/description/

>>>  Memorization Approach

int solve(int i, int j, vector<vector<int>> &triangle, vector<vector<int>>&dp)
    {
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i == triangle.size() - 1) 
            return triangle[i][j];

        int down = solve(i+1, j, triangle, dp);
        int diagonal = solve(i+1, j+1, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }
int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(0, 0, triangle, dp);
    }
---------------------------------------------------------------------------------
>>>   Tabulation Approach

int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        
        for(int j = 0; j < n; j++)
            dp[n-1][j] = triangle[n-1][j];
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j = 0; j <= i; j++ )
            {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
---------------------------------------------------------------------------------
>>>   Space Optimization Approach
int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> post(n);
        
        for(int j = 0; j < n; j++)
            post[j] = triangle[n-1][j];
        
        for(int i=n-2; i>=0; i--)
        {
            vector<int> tmp(i+1);
            for(int j = 0; j <= i; j++ )
            {
                tmp[j] = triangle[i][j] + min(post[j], post[j+1]);
            }
            post = tmp;
        }
        return post[0];
    }
