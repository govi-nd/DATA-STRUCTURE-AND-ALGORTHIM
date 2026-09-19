/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(p->val > root->val && q->val > root->val ){
            auto ans = lowestCommonAncestor(root->right,p,q);
            if(ans) return ans;
        }
        if(p->val < root->val && q->val < root->val){
            auto leftAns = lowestCommonAncestor(root->left,p,q);
            if(leftAns) return leftAns;
        }
         return root;
    }
};