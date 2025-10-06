// Problem Link: https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1

Apporach 1: // Time: O(n) , Space: O(d)
-----------
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n = arr.size();
        
        d %= n;
        
        vector<int> tmp;
        
        for(int i=0; i<n; i++)
        {
            if(i < d) tmp.push_back(arr[i]);
            else {
                arr[i-d] = arr[i];
            }
        }
        
        for(int i = n - d, j=0; i < n; i++, j++)
            arr[i] = tmp[j];

    }
----------------
Apporach 2: // Time: O(n) , Space: O(1)
----------  
  void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d %= n;
        
        // Reverse the first d elements
        reverse(arr.begin(), arr.begin() + d);
        // Reverse the remaining n-d elements
        reverse(arr.begin() + d, arr.end());
        // Reverse the entire array
        reverse(arr.begin(), arr.end());
    }
