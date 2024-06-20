Problem Link: https://leetcode.com/problems/maximum-total-damage-with-spell-casting/description/


>>> Tabulation approach
   
long long maximumTotalDamage(vector<int>& power) {
        
        map<int, int> cnt;
        for(int i=0; i<power.size(); i++)
            cnt[power[i]]++;
        
        sort(power.begin(), power.end());
        int n = unique(power.begin(), power.end()) - power.begin();

        vector<long long> dp(n);
        dp[0] = power[0]*(cnt[power[0]]*1LL);

        for(int i=1; i<n; i++)
        {
            int j = i - 1;
            while(j >= 0 and power[i] - power[j] <= 2)
                j--;
            
            long long take = power[i]*cnt[power[i]];
            if(j < 0) dp[i] = max(dp[i-1], take);
            else dp[i] = max(dp[i-1], dp[j] + take);
        }
        return dp[n-1];
    }
