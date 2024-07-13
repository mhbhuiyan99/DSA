Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/

>>> BinarySearch
  
int search(vector<int>& a, int target) {
    
        int l = 0, r = a.size()-1;
        
        while(l <= r)
        {
            int mid = (l+r) >> 1;
            if(a[mid] == target) return mid;

            if(a[mid] >= a[l])
            {
                if(target < a[mid] and target >= a[l])
                    r = mid - 1;
                else l = mid + 1;
            }
            else 
            {
                if(target > a[mid] and target <= a[r])
                    l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
