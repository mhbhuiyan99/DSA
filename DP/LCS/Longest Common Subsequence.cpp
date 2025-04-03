Problem Link : https://leetcode.com/problems/longest-common-subsequence/description/

>>>> --- Recursive Solution (TLE) ------- <<<<

int solve(string &a, string &b, int i, int j)
    {
        if(i == a.size()) return 0;
        if(j == b.size()) return 0;

        int ans = 0;

        if(a[i] == b[j])
            ans = 1 + solve(a,b,i+1,j+1);
        else ans = max(solve(a,b,i+1,j), solve(a,b,i,j+1));

        return ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, text2, 0, 0);
    }


>>>>> ----------  Top-Down DP ---------- <<<<<<

int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {
        if(i == a.size()) return 0;
        if(j == b.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        if(a[i] == b[j])
            ans = 1 + solve(a,b,i+1,j+1,dp);
        else ans = max(solve(a,b,i+1,j,dp), solve(a,b,i,j+1,dp));

        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {

        vector< vector<int>> dp(text1.size(), vector<int> (text2.size(), -1));
        return solve(text1, text2, 0, 0, dp);
    }

>>>>>> ----- Tabulation ----- <<<<<<

int longestCommonSubsequence(string a, string b) {
        
        vector<vector<int>> dp(a.size() + 1, vector<int> (b.size() + 1, 0));

        for(int i = a.size() - 1; i >= 0; i--)
        {
            for(int j = b.size() - 1; j >= 0; j--)
            {
                if(a[i] == b[j]) dp[i][j] = 1 + dp[i+1][j+1]; 
                else dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
    }



