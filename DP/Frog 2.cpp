Problem Link : https://atcoder.jp/contests/dp/tasks/dp_b

>>>  Memorization Approach
  
ll solve(ll idx, ll k, vector<ll> &v, vector<ll> &dp)
{
    if(idx == 0) return 0;
    if(dp[idx] != -1) return dp[idx];

    ll mn = INT_MAX;

    for(ll j = 1; j <= k; j++)
    {
        if(idx - j >= 0)
        {
            ll jump = solve(idx - j, k, v, dp) + abs(v[idx] - v[idx - j]);
            mn = min(mn, jump);
        }
    }
    return dp[idx] = mn;
}

---------------------------------------------------------------------
>>>  Tabulation Approach

ll solve(ll n, ll k, vector<ll> &v)
{
    vector<ll> dp(n, INT_MAX);
    dp[0] = 0;

    for(ll i = 1; i < n; i++)
    {
        for(ll j = 1; j <= k; j++)
        {
            if(i - j >= 0)
            {
                ll jump = dp[i - j] + abs(v[i] - v[i - j]);
                dp[i] = min(dp[i], jump);
            }
        }
    }
    return dp[n-1];
}
