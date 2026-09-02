class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL)
            return NULL;

        if(root == p || root == q)
            return root;

        TreeNode* left = solve(root->left, p, q);
        TreeNode* right = solve(root->right, p, q);

        if(left != NULL && right != NULL)
            return root;

        if(left != NULL)
            return left;

        return right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};