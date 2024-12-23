Problem Link: https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);

        int cnt = 0;
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> id(sz, 0);
            /*
            std::iota is a utility function defined in the <numeric> header.
            Its purpose is to fill a range with sequentially increasing values starting from a given initial value.

            The idx vector is filled with integers starting from 0, with each subsequent element increasing by 1.
            For example, if idx is a vector of size 5, after the iota call, it will contain:

            id = {0, 1, 2, 3, 4};
            */
            iota(id.begin(), id.end(), 0);

            vector<int> v(sz,0);
            for(int i = 0; i < sz; i++)
            {
                auto cur = q.front();
                q.pop();

                v[i] = cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }

            sort(id.begin(), id.end(), [&](int i, int j){
                return v[i] < v[j];
            });

            for(int i = 0; i < sz; )
            {
                int j = id[i];
                if(j != i)
                {
                    cnt++;
                    swap(id[i], id[j]);
                }
                else i++;
            }
        }
        return cnt;
    }
};
