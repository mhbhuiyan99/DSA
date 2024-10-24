LeetCode (Premium) : https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/solutions/1499842/C++-Sliding-Window-(+-Cheat-Sheet)/
GFG : https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

    int longestKSubstr(string s, int k) {
    
        int i = 0, j = 0, ans = -1;
        map<char, int> cnt;
        
        while(j < s.size())
        {
            cnt[s[j]]++;
            
            if(cnt.size() > k)
            {
                cnt[s[i]]--;
                if(cnt[s[i]] == 0)
                    cnt.erase(s[i]);
                i++;
            }
            
            if(cnt.size() == k)
            {
                ans = max(ans, j - i  + 1);
            }
            j++;
        }
        return ans;
    }
