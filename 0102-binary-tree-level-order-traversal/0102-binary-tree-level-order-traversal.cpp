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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> bfs;
        TreeNode* temp = root;
        queue<TreeNode*> q;
        q.push(temp);
        while(!q.empty()){
            vector<int> level;
            int levelSize = q.size();
            for(int i =0;i< levelSize; i++){
                TreeNode* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            bfs.push_back(level);
        }
        return bfs;
    }
};