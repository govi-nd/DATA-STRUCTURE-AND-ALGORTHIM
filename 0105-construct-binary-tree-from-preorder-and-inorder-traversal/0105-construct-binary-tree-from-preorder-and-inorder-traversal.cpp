class Solution {
public:
    void buildMap(vector<int>& inorder, unordered_map<int, int>& mp) {

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& preorder, int& preIdx, int inStart, int inEnd,
                    unordered_map<int, int>& mp) {

        if (inStart > inEnd)
            return NULL;

        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        int rootPos = mp[rootVal];

        root->left = solve(preorder, preIdx, inStart, rootPos - 1, mp);

        root->right = solve(preorder, preIdx, rootPos + 1, inEnd, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int, int> mp;
        buildMap(inorder, mp);

        int preIdx = 0;

        return solve(preorder, preIdx, 0, inorder.size() - 1, mp);
    }
};