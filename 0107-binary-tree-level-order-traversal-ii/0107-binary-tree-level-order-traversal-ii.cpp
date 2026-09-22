class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> level;

            while (n--) {
                TreeNode* t = q.front();
                q.pop();

                level.push_back(t->val);

                if (t->left)
                    q.push(t->left);

                if (t->right)
                    q.push(t->right);
            }

            ans.push_back(level);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};