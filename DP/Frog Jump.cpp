Problem Link : https://bit.ly/3JPcoOx

>>>  Top-Down approach  

int solve(int n, vector<int> &heights, vector<int> &dp)
{
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];

    int oneMove = solve(n - 1, heights, dp) + abs(heights[n] - heights[n-1]);
    int twoMove = INT_MAX;
    if(n > 1) 
        twoMove = solve(n-2, heights, dp) + abs(heights[n] - heights[n-2]);

    return dp[n] = min(oneMove, twoMove);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    return solve(n-1, heights, dp);
}

--------------------------------------------------------------------------------
>>>  Tabulation Approach

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n);
    dp[0] = 0;
    for(int i=1; i < n; i++)
    {
        int oneMove = dp[i-1] + abs( heights[i] - heights[i-1] );
        int twoMove = INT_MAX;
        if(i > 1)
            twoMove = dp[i-2] + abs( heights[i] - heights[i-2] );
        dp[i] = min(oneMove, twoMove);
    }
    return dp[n-1];
}
