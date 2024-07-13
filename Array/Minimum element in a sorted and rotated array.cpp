Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

>>> BinarySearch
  
int findMin(vector<int>& arr) {
        
        int l = 0, r = arr.size()-1;
        while(l < r)
        {
            int mid = (l+r) >> 1;
            
            if(arr[mid] < arr[r])
                r = mid;
            else l = mid + 1;
        }
        return arr[l];
    }
};
