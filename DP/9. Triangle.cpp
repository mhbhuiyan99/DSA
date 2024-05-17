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
