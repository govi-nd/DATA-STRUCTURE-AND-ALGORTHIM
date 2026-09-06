class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {

            int n = q.size();
            vector<int> path;

            for (int i = 0; i < n; i++) {

                TreeNode* node = q.front();
                q.pop();

                path.push_back(node->val);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            if (!leftToRight)
                reverse(path.begin(), path.end());

            ans.push_back(path);

            leftToRight = !leftToRight;
        }

        return ans;
    }
};