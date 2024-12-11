Problem Link: https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/

int maximumBeauty(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = 0;

        for(int i=0,j=0; i<n; i++)
        {
            if(nums[i] - nums[j] <= 2*k)
                ans = max(ans, i - j + 1);
            else j ++;
        }

        return ans;
    }
