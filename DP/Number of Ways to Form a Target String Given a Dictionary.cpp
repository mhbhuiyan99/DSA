Problem Link : https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/

>>> --- Approach-1 (Recur + Memo) --- <<<
  
class Solution {
public:
    int m,k;
    const int MOD = 1e9 + 7;
    int dp[1001][1001];

    int solve(int i, int j, vector<vector<long long>>&cnt, string target)
    {
        if(i == m) return 1;
        if(j == k) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int not_take = solve(i, j+1, cnt, target) % MOD;
        int take = ((cnt[target[i] - 'a'][j]) * (solve(i+1, j+1, cnt, target))) % MOD;

        return dp[i][j] = (take + not_take) % MOD;
    }

    int numWays(vector<string>& words, string target) {
        
        m = target.size();
        k = words[0].size();

        vector< vector<long long> > cnt(26, vector<long long> (k));

        for(int col = 0; col < k; col++)
        {
            for(auto s : words)
                cnt[s[col] - 'a'][col]++;
        }
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, cnt, target);
    }
};
-------------------------------------------

>>> --- Approach-2 (Bottom Up DP) --- <<<

class Solution {
public:

    const int MOD = 1e9 + 7;
    int numWays(vector<string>& words, string target) {
        
        int m = target.length();
        int k = words[0].size();

        vector< vector<long long> > cnt(26, vector<long long> (k,0));

        for(int col = 0; col < k; col++)
        {
            for(string &s : words) // ---> without '&' Memory Limit Exceeded
                cnt[s[col] - 'a'][col]++;
        }
        vector<vector<long long>> dp(m+1,vector<long long> (k+1));

        dp[0][0] = 1;

        for(int i=0; i<=m; i++)
        {
            for(int j=0; j<=k; j++)
            {
                if(j<k) dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % MOD;
                if(i < m and j < k) dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]*cnt[target[i] - 'a'][j]) % MOD;
            }
        }
        return dp[m][k];
    }
};
