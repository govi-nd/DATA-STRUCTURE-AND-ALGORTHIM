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
    void buildMap(vector<int>& inorder, unordered_map<int, int>& mp) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& postorder, int& postIdx, int inStart,
                    int inEnd, unordered_map<int, int>& mp) {

        if (inStart > inEnd || postIdx < 0)
            return NULL;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int rootPos = mp[rootVal];
        root->right = solve(postorder, postIdx, rootPos + 1, inEnd, mp);
        root->left = solve(postorder, postIdx, inStart, rootPos - 1, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        buildMap(inorder, mp);

        int postIdx = postorder.size()-1;

        return solve(postorder, postIdx, 0, inorder.size() - 1, mp);
    }
};
