Problem Link : https://leetcode.com/problems/n-queens/description/

// Approach - 1 > Runtime Beats 54.78%

class Solution {
public:

    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        int tmpRow = row;
        int tmpCol = col;

        // left 
        while(col >= 0)
        {
            if(board[row][col] == 'Q') return false;
            col--;
        }
        col = tmpCol;
        // upperLeft
        while(row >= 0 and col >= 0)
        {
            if(board[row][col] == 'Q') return false;
            col--;
            row--;
        }
        row = tmpRow;
        col = tmpCol;
        // lowerLeft
        while(row < n and col >= 0)
        {
            if(board[row][col] == 'Q') return false;
            col--;
            row++;
        }
        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++)
        {
            if(isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');

        for(int i=0; i<n; i++)
            board[i] = s;
        
        solve(0, board, ans, n);

        return ans;
    }
};

-----------------------------------------------

 Approach - 2 > 





  
