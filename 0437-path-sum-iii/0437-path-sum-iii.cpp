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
    int count = 0;
    
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        dfsAll(root, targetSum);          // Search starting from every node
        pathSum(root->left, targetSum);    // Also start from left subtree
        pathSum(root->right, targetSum);   // Also start from right subtree
        return count;
    }
    
    void dfsAll(TreeNode* root, long long targetSum) {
        if (!root) return;
        
        if (root->val == targetSum) {
            count++;
        }
        
        dfsAll(root->left, targetSum - root->val);
        dfsAll(root->right, targetSum - root->val);
    }
};