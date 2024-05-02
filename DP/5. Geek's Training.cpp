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

int maximumPoints(vector<vector<int>>& points, int n) {
        
        vector<vector<int>> dp(n, vector<int>(4, 0));
        
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][1], points[0][0]);
        dp[0][3] = max({points[0][0], points[0][1], points[0][2]});
        
        for(int day = 1; day < n; day++)
        {
            for(int lst = 0; lst < 4; lst++)
            {
                for(int task = 0; task < 3; task++)
                {
                    if(lst != task)
                    {
                        dp[day][lst] = max(dp[day][lst], dp[day-1][task] + points[day][task]);
                    }
                }
            }
        }
        return dp[n-1][3];
    }
---------------------------------------------------------------------------------------

>>> Space Optimization Approach


