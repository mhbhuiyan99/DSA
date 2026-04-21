// Problem Link: https://leetcode.com/problems/palindromic-substrings/

// Approach - 1 :: O(n^3)

    bool ck(string &s, int i, int j) {
        if(i > j)
            return true;
        if(s[i] == s[j])
            return ck(s, ++i, --j);
        return false;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(ck(s, i, j))
                    cnt++;
            }
        }

        return cnt;
    }
-----------------------------------------------

// Approach - 2 : O(n^2)

    int NoOfSubWithCenter(string &s, int left, int right) {
        int cnt = 0;

        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            cnt++;
            left--;
            right++;
        }

        return cnt;
    }

    int countSubstrings(string s) {
        int cnt = 0;
        int n = s.size();

        for(int i=0; i<n; i++) {
            cnt += NoOfSubWithCenter(s, i, i); // odd length
            cnt += NoOfSubWithCenter(s, i, i+1);
        }

        return cnt;
    }
