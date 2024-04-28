Problem Link: https://leetcode.com/problems/house-robber-ii/description/

//  using (3)'House Robber' problem's code with space optimization  
.
int solve(int i, int n, vector<int> &nums)
    {
        int pre1 = 0;
        int pre2 = 0;
        for(; i < n; i++)
        {
            int take = pre2 + nums[i];
            int not_take = pre1;
            int cur = max(take, not_take);

            pre2 = pre1;
            pre1 = cur;
        }
        return pre1;
    }
int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n == 1 ? nums[0] : 0;
        return max(solve(0, n-1, nums),solve(1, n, nums));
}
