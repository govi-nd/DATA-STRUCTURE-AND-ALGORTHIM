
class Solution {
public:
    void solve(TreeNode* root, int targetSum, int& sum, vector<int>& path,
               vector<vector<int>>& ans) {

        if (root == NULL)
            return;

        // Add current node to val to sum and add it in path
        sum += root->val;
        path.push_back(root->val);

        // Check leaf node
        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum)
                ans.push_back(path);

            // Backtrack before returning
            sum -= root->val;
            path.pop_back();
            return;
        }

        // Explore left subtree
        solve(root->left, targetSum, sum, path, ans);

        // Explore right subtree
        solve(root->right, targetSum, sum, path, ans);

        // Remove current node before returning to parent
        sum -= root->val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int sum =0;
        solve(root,targetSum,sum,path ,ans);
        return ans;
    }
};
