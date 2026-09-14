class Solution {
int sum = 0;
public:
    void reverseInorder(TreeNode* root) {
        if (root==NULL) return;

        reverseInorder(root->right);

        sum += root->val;
        root->val = sum;

        reverseInorder(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        reverseInorder(root);
        return root;
    }
};