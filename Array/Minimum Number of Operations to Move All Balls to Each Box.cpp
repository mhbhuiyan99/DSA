Problem Link : https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

>>> ---- Optimized - O(n) ---- <<<

vector<int> minOperations(string boxes) {
        
        int n = boxes.size();
        vector<int> ans(n,0);

        for(int i=0, ops = 0, cnt = 0; i<n; i++)
        {
            ans[i] += ops;
            cnt += (boxes[i] - '0');
            ops += cnt;
        }

        for(int i=n-1, ops = 0, cnt = 0; i>=0; i--)
        {
            ans[i] += ops;
            cnt += (boxes[i] - '0');
            ops += cnt;
        }

        return ans;
    }
