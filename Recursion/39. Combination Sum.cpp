Problem Link: https://leetcode.com/problems/combination-sum/

class Solution {
public:
    
    void findComb(int idx, int t, vector<int> &arr, vector<vector<int> > &ans, vector<int> &v)
    {
        if(idx == arr.size() or t == 0)
        {
            if(t == 0)
            {
                ans.push_back(v);
            }
            return;
        }
        
        if(arr[idx] <= t)
        {
            v.push_back(arr[idx]);
            findComb(idx, t - arr[idx], arr, ans, v);
            v.pop_back();
        }
        findComb(idx + 1, t, arr, ans, v);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector< vector<int> > ans;
        vector<int> v;
        
        findComb(0, target, candidates, ans, v);
        
        return ans;
    }
};
