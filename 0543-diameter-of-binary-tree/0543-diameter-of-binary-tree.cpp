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
    int getHeightAndDia(TreeNode* root, int &dia) {
        if (root == NULL) 
            return 0;

        int leftHeight = getHeightAndDia(root->left, dia);
        int rightHeight = getHeightAndDia(root->right, dia);

        // Diameter passing through current node
        dia = max(dia, leftHeight + rightHeight);

        // Return height to parent
        int totalHeight = max(leftHeight, rightHeight) + 1;

        return totalHeight;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;

        getHeightAndDia(root, diameter);

        return diameter;
    }
};