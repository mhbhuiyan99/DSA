// Problem Link: https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, n = nums.size();
        vector<int> pre(n);
        unordered_map<int, int> ache;

        pre[0] = nums[0];
        for(int i = 1; i < n; i++)
            pre[i] = pre[i-1] + nums[i];

        for(int i = 0; i < n; i++){
            cnt += (pre[i] == k);

            if(ache.find(pre[i] - k) != ache.end())
                cnt += ache[pre[i] - k];

            ache[pre[i]]++;
        }
        return cnt;
    }
};
