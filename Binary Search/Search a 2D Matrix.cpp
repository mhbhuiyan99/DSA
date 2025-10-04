// Problem Link: https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int st = 0, ed = r*c - 1;

        while(st <= ed) {
            int mid = st + (ed - st)/2;

            int ele = matrix[mid/c][mid%c];

            if(ele == target)
                return true;
            if(ele < target)
                st = mid + 1;
            else ed = mid - 1;
        }
        return false;
    }
};
