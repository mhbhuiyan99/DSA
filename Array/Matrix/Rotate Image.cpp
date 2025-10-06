// Problem Link: https://leetcode.com/problems/rotate-image/description/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: **Transpose** the matrix
        // Swap elements across the main diagonal
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
      
        // Step 2: **Reverse** each row
        // Use the std::reverse algorithm
        for(int i=0; i<n; i++) {
            for(int j=0; j<n/2; j++) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }
};
