Problem Link : https://leetcode.com/problems/permutations/description/

//  Approach - 1: using next_permutation  [runtime beats 43.69%] 

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do
        {
            ans.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        
        return ans;
    }
};

//  Approach - 2: Recursion [runtime beats 100%]

class Solution {
public:
    void generate (vector<int> &nums, vector<vector<int> > &ans, vector<int> &store, int n, int cnt[])
    {
        if(store.size() == n)
        {
            ans.push_back(store);
            return;
        }
        for(int i=0; i<n; i++)
        {
            if(!cnt[i])
            {
                store.push_back(nums[i]);
                cnt[i] = 1;
                generate(nums, ans, store, nums.size(), cnt);
                cnt[i] = 0;
                store.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> store;
        int cnt[7] = {0};
        generate(nums, ans, store, nums.size(), cnt);
        
        return ans;
    }
};

//  Approach - 3: Swap and Recursion  [runtime beats 100% and using less memory]

class Solution {
public:
    void swap_and_permute(vector<int>&nums, vector<vector<int>> &ans, int idx)
    {
        if(idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++)
        {
            swap(nums[idx], nums[i]);
            swap_and_permute(nums, ans, idx+1);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        swap_and_permute(nums, ans, 0);
        return ans;
    }
};
