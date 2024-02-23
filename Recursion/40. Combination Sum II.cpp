Problem Link: https://leetcode.com/problems/combination-sum-ii/
class Solution {
public:
    
    void find(int id, vector<int>&c, vector<int>&tmp, vector<vector<int>>&ans, int t)
    {
        if(t == 0)
        {
            ans.push_back(tmp);
            return;
        }
        
        for(int i=id; i<c.size(); i++)
        {
            if(i > id and c[i] == c[i-1]) continue;
            if(c[i] > t) break;
            tmp.push_back(c[i]);
            find(i+1, c, tmp, ans, t-c[i]);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        vector< vector<int> > ans;
        vector<int> tmp;
        find(0, c, tmp, ans, target);
        return ans;
    }
};
