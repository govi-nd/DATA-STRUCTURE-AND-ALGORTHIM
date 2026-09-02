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
    int height(TreeNode* root , bool &ans){
        if(root==NULL) return 0;
        if(ans!=true) return 0;
        int leftSubTreeHeight = height(root->left,ans);
        int rightSubTreeHeight = height(root->right,ans);
        int diff = abs(leftSubTreeHeight - rightSubTreeHeight );
        if(diff>1) {
            ans=false;
        }
        return max(leftSubTreeHeight,rightSubTreeHeight)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        int sol = height(root,ans);
        return ans;
    }
};