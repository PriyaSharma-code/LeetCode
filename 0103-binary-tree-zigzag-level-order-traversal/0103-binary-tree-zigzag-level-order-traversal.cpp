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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>> bfs;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty()){
            int levelSize = q.size();
            vector<int> level(levelSize);
            for(int i = 0 ; i< levelSize; i++){
                TreeNode* cur = q.front();
                q.pop();
                int index = leftToRight ? i : (levelSize -i -1);
                level[index] = cur->val;
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }            
            }
            leftToRight = !(leftToRight);
            bfs.push_back(level);
        }
        return bfs;

    }
};