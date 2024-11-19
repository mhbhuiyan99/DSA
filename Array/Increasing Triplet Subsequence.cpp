Problem Link: https://leetcode.com/problems/increasing-triplet-subsequence?envType=study-plan-v2&envId=leetcode-75

bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        int mn = INT_MAX, mid = mn;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] > mid) return true;
            else if(nums[i] < mn) mn = nums[i];
            else if(nums[i] < mid and nums[i] > mn) mid = nums[i];
        }
        return false;
    }
