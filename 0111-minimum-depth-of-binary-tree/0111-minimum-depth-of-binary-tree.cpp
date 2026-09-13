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
    void solve(TreeNode* root , int path , int &ans){
        if(root==NULL) return;
        path++;
        if(root->left == NULL && root->right==NULL){
            ans = min(ans,path);
            path--;
        }
        solve(root->left,path,ans);
        solve(root->right,path,ans);
        path--;

    }
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int ans = INT_MAX;
        int path = 0 ;
        solve(root,path,ans);
        return ans;
    }
};