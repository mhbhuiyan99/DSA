Problem Link : https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

class Solution {
public:
    int play(int n, int start, int k, vector<int> &v)
    {
        if(v.size() == 1)
            return v[0];
        
        int idx = (start + k - 1) % n;
        v.erase(v.begin() + idx);
        start = (idx != n - 1 ? idx : 0);
        return play(n-1,start, k, v);
    }

    int findTheWinner(int n, int k) {
        vector<int> v;
        for(int i=1; i<=n; i++)
            v.push_back(i);
        return play(n, 0, k, v);
    }
};
