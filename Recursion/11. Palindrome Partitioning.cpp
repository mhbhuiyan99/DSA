Problem Link: https://leetcode.com/problems/palindrome-partitioning/description/

class Solution {
public:

    bool isPalindrome(string s, int i, int j)
    {
        while(i < j)
        {
            if(s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }

    void partitionGenerate(int idx, string s, vector<string>&tmp, vector<vector<string>>&ans)
    {
        if(idx == s.size())
        {
            ans.push_back(tmp);
            return;
        }
        for(int i = idx; i < s.size(); i++)
        {
            if(isPalindrome(s, idx, i))
            {
                tmp.push_back(s.substr(idx, i - idx + 1));
                partitionGenerate(i+1, s, tmp, ans);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        partitionGenerate(0, s, tmp, ans);
        return ans;
    }
};
