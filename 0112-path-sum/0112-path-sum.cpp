class Solution {
public:
    void solve(TreeNode* root, int targetSum, int& sum, bool& ans) {

        if (root == NULL || ans == true)
            return;

        // Add current node to path sum
        sum += root->val;

        // Check leaf node
        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum)
                ans = true;

            // Backtrack before returning
            sum -= root->val;
            return;
        }

        // Explore left subtree
        solve(root->left, targetSum, sum, ans);

        // Explore right subtree
        solve(root->right, targetSum, sum, ans);

        // Remove current node before returning to parent
        sum -= root->val;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = false;

        solve(root, targetSum, sum, ans);

        return ans;
    }
};
