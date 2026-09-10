class Solution {
public:
    int ans = 0;

    pair<int, int> solve(TreeNode* root) {

        if (root == NULL)
            return {0, 0};

        // Get information about left subtree
        auto left = solve(root->left);

        // Get information about right subtree
        auto right = solve(root->right);

        // Current subtree
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        // Check average
        if (sum / count == root->val)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};