// Problem Link: https://leetcode.com/problems/reordered-power-of-2/

class Solution {

public:
    string getNum(int n)
    {
        string s = to_string(n);
        sort(s.begin(), s.end());
        return s;
    }

    bool reorderedPowerOf2(int n) {
        string num = getNum(n);

        for(int i=0; i<31; i++)
        {
            if(getNum(1<<i) == num)
                return true;
        }
        return false;
    }
};
