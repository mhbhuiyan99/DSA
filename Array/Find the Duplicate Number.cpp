Problem Link : https://leetcode.com/problems/find-the-duplicate-number/description/

>>> Using Floyds Hare and Tortoise Algorithm ---- [ slow and fast pointer ]

int findDuplicate(vector<int>& A) {
        if(A.size() <= 1) return -1;
    
        int slow = A[0];
        int fast = A[0];
        
        do{
            slow = A[slow];
            fast = A[A[fast]];
        } while(slow != fast);
        
        slow = A[0];
        while(slow != fast)
        {
            slow = A[slow];
            fast = A[fast];
        }
        return slow;
  }
