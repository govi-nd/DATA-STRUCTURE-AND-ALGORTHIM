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
    void solve(TreeNode*a,TreeNode*b , bool&ans){
        if(a==NULL && b==NULL) return;
        if(!a){
            ans=false; return;
        }
        if(!b){
            ans=false;return;
        }
        cout<<a->val<<" " <<b->val<<" " <<endl;
        if(a->val!=b->val){
            ans=false;
            return;
        }
        solve(a->left,b->left,ans);
        solve(a->right,b->right,ans);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans=true;
        solve(p,q,ans);
        return ans;
    }
};