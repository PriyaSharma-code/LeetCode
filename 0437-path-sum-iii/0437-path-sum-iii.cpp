class Solution {
public:
    int count = 0;

    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        helperPathSum(root, targetSum, path);
        return count;
    }

    void helperPathSum(TreeNode* root, int targetSum, vector<int>& path) {
        if (!root) return;

        path.push_back(root->val);
        long long sum = 0;

        // Check all prefix sums
        for (int i = path.size() - 1; i >= 0; i--) {
            sum += path[i];
            if (sum == targetSum) count++;
        }

        if(root->left) helperPathSum(root->left, targetSum, path);
        if(root->right) helperPathSum(root->right, targetSum, path);

        // Backtrack
        path.pop_back();
    }
};