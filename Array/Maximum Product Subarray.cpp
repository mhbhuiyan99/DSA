Problem Link: https://leetcode.com/problems/maximum-product-subarray/description/

>>>  Using Kadane's Algorithm: 

int maxProduct(vector<int>& nums) {
        double mx = nums[0];
        double mn = mx;
        double ans = mn;

        for(int i=1; i<nums.size(); i++)
        {
            double tmp = max({1.0*nums[i], mx*nums[i], mn*nums[i]});
            mn = min({1.0*nums[i], mx*nums[i], mn*nums[i]});
            mx = tmp;
            ans = max(mx, ans);
        }
        return ans;
    }
----------------------------------------------------------------------
>>> Using Traversing

    int maxProduct(vector<int>& nums) {
        double  L_to_R = 1;
        double R_to_L = 1;
        double ans = nums[0];
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            if(L_to_R == 0) L_to_R = 1;
            if(R_to_L == 0) R_to_L = 1;

            L_to_R *= nums[i];
            R_to_L *= nums[n-i-1];

            ans = max({ans, L_to_R, R_to_L});
        }
        return ans;
    }
  
