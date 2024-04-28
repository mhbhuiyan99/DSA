Problem Link:
  LeetCode : https://leetcode.com/problems/permutation-sequence/description/
  GFG      : https://www.geeksforgeeks.org/problems/find-kth-permutation-0932/1

public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int>numbers;
        for(int i=1; i<n; i++)
        {
            fact *= i;
            numbers.push_back(i);
        }   numbers.push_back(n);

        string ans = "";
        k--;
        while(true)
        {
            ans = ans + to_string(numbers[k/fact]);
            numbers.erase(numbers.begin() + k/fact);
            if(numbers.size() == 0)
                break;
            k %= fact;
            fact /= numbers.size();
        }
        return ans;
    }
};
