/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        int depth = 1;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                depth++;
                if (!q.empty())
                    q.push(NULL);
            } else {

                if (node->left == NULL && node->right == NULL)
                    return depth;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return depth;
    }

    // void solve(TreeNode* root , int path , int &ans){
    //     if(root==NULL) return;
    //     path++;
    //     if(root->left == NULL && root->right==NULL){
    //         ans = min(ans,path);
    //         path--;
    //     }
    //     solve(root->left,path,ans);
    //     solve(root->right,path,ans);
    //     path--;

    // }
    // int minDepth(TreeNode* root) {
    //     if(root==NULL) return 0;
    //     int ans = INT_MAX;
    //     int path = 0 ;
    //     solve(root,path,ans);
    //     return ans;
    // }
};
