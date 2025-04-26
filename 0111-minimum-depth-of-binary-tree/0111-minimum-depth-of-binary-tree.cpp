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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = minDepth(root->left);
        root->left = nullptr;
        int right = minDepth(root->right);
        root->right = nullptr;
        if(left == 0) {
            if(right == 0) return 1;
            else return right + 1;
        } else {
            if(right == 0) return left + 1;
            else return min(left, right) + 1;
        }
    }
    
};