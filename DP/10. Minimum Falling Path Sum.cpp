Problem Link: https://leetcode.com/problems/minimum-falling-path-sum/description/

>>>  Memorization Approach

int solve(int i, int j, vector<vector<int>>&matrix, vector<vector<int>>&dp)
    {
        if(i == 0) return dp[i][j] = matrix[i][j];
        if(dp[i][j] != -100000) return dp[i][j];

        int cost = solve(i-1, j, matrix, dp);
        if(j-1 >= 0) cost = min(cost, solve(i-1, j-1, matrix, dp));
        if(j+1 < matrix.size()) cost = min(cost, solve(i-1, j+1, matrix, dp));

        return dp[i][j] = matrix[i][j] + cost;
    }
int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n,-100000));
        for(int j = 0; j < n; j++)
        {
            ans = min(ans, solve(n-1,j,matrix,dp));
        }
        return ans;
    }
------------------------------------------------------------------------------
