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
     int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) { return 0; }

        int maxw = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while(!q.empty())
        {
            int n = q.size();
            unsigned long long start = q.front().second; // The position of the first node in the current level
            unsigned long long end = q.back().second;   // The position of the last node in the current level
            maxw = max(maxw, int(end - start + 1));     // Update the maximum width

            for (int i = 0; i < n; i++)
            {
                pair<TreeNode*, unsigned long long> node = q.front(); 
                q.pop(); 

                unsigned long long index = node.second - start; // Normalized index to prevent overflow
                if (node.first->left != nullptr) {
                    q.push({node.first->left, 2 * index+1});
                }
                if (node.first->right != nullptr) {
                    q.push({node.first->right, 2 * index + 2});
                }
            }
        }
        return maxw;
    }
};