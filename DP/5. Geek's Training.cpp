Problem Link : https://www.geeksforgeeks.org/problems/geeks-training/1

>>> Memorization Approach

int solve(vector<vector<int>> &points, vector<vector<int>> &dp, int n, int lst)
    {
        if(dp[n][lst] != -1) return dp[n][lst];
        if(n == 0)
        {
            int mx = 0;
            for(int i=0; i<3; i++)
            {
                if(i != lst) mx = max(mx, points[n][i]);
            }
            return dp[n][lst] = mx;
        }
        
        int mx = 0, earn = 0;
        for(int i=0; i<3; i++)
        {
            if(i != lst)
            {
                earn = points[n][i] + solve(points, dp, n-1, i);
            }
            mx = max(mx, earn);
        }
        return dp[n][lst] = mx;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(points, dp, n-1, 3);
    }

---------------------------------------------------------------------------------

>>> Tabulation Approach

