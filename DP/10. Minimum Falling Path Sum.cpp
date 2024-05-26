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

>>>    Tabulation Approach

int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));

        for(int i=0; i<n; i++)
            dp[0][i] = matrix[0][i];

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int cost = dp[i-1][j];
                if(j > 0) cost = min(cost, dp[i-1][j-1]);
                if(j + 1 < n) cost = min(cost, dp[i-1][j+1]);
                dp[i][j] = cost + matrix[i][j];
            }
        }
        int ans = dp[n-1][0];
        for(int i=1; i<n; i++)
            ans = min(ans, dp[n-1][i]);

        return ans;
    }
