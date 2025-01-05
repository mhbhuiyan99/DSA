Problem Link : https://leetcode.com/problems/shifting-letters-ii/description/

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = s.size();
        vector<int> IncDec(n + 1, 0);

        for(auto u : shifts)
        {
            IncDec[u[0]] += (u[2] > 0 ? 1 : -1);
            IncDec[u[1] + 1] -= (u[2] > 0 ? 1 : -1); // stop the effect of Inc. and Dec
        }

        for(int i=1; i<=n; i++)
            IncDec[i] += IncDec[i-1];

        for(int i=0; i<n; i++)
        {
            int no_of_change = (s[i] - 'a' + IncDec[i]) % 26;
            no_of_change = (no_of_change + 26) % 26; // '-' to '+'
            s[i] = 'a' + no_of_change;
        }
        return s;
    }
};
