Problem Link : https://leetcode.com/problems/3sum/description/

>>> Using Set

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {

        int n = arr.size();
        sort(arr.begin(), arr.end());
        set<vector<int>> ans;
        for(int i=0; i<n-2; i++)
        {
            unordered_set<int> s; // we can use map here
            int tmp = INT_MAX; /* without using tmp : TLE */
            for(int j = i+1; j < n; j++)
            {
                int x = -(arr[i] + arr[j]);
                if(tmp == x) continue;
                if(s.find(x) != s.end())
                    ans.insert({arr[i], x, arr[j]}),
                    tmp = arr[j];
                else s.insert(arr[j]);
            }
        }
        vector<vector<int>> v(ans.begin(), ans.end());
        return v;
    }
};
---------------------------------------------------------------

>>> Using 2 pointer

vector<vector<int>> threeSum(vector<int>& arr) {

        int n = arr.size();
        sort(arr.begin(), arr.end());
        set<vector<int>> ans;
        for(int i=0; i<n-2; i++)
        {
            int l = i+1;
            int r = n-1;

            while(l < r)
            {
                int sum = arr[i] + arr[l] + arr[r];
                if(sum == 0) 
                    ans.insert({arr[i], arr[l], arr[r]}),
                    l++, r--;
                else if(sum > 0) r--;
                else l++;
            }
        }
        vector<vector<int>> v(ans.begin(), ans.end());
        return v;
    }
