
Problem Link : https://www.geeksforgeeks.org/problems/subset-sums2234/1

class Solution
{
public:
    void subsum(vector<int> &arr, vector<int> &tmp, int i, int sum, int n, vector<int>&s)
    {
        if(i == n) 
        {
            s.push_back(sum);
            return;
        }
        subsum(arr, tmp, i+1, sum + arr[i], n, s);
        subsum(arr, tmp, i+1, sum, n, s);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> s;
        vector<int> tmp;
        sort(arr.begin(), arr.end());
        subsum(arr, tmp, 0, 0, N, s);
        sort(s.begin(), s.end());
        return s;
    }
};
