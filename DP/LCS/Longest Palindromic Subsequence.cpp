Problem Link : https://leetcode.com/problems/longest-palindromic-subsequence/description/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t(s.rbegin(), s.rend());

        vector<vector<int>> dp(s.size()+1, vector<int> (s.size() + 1, 0));

        for(int i = s.size() - 1; i >= 0; i--)
        {
            for(int j = t.size() - 1; j >= 0; j--)
            {
                if(s[i] == t[j]) dp[i][j] = 1 + dp[i+1][j+1];
                else dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};
