
problem link: https://leetcode.com/problems/subsets-ii/description/

class Solution {
public:
    
    void subset(vector<int> &nums, int idx, vector<int> &tmp, vector<vector<int>>&ans)
    {
        ans.push_back(tmp);
        for(int i = idx; i<nums.size(); i++)
        {
            if(i > idx and nums[i] == nums[i-1]) continue;
            tmp.push_back(nums[i]);
            subset(nums, i+1, tmp, ans);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector< vector<int> > ans;
        vector<int> tmp;
        subset(nums, 0, tmp, ans);
        return ans;
    }
};
