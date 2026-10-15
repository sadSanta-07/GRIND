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
    int find(TreeNode* root, int currsum) {
        if (!root) {
            return 0;
        }

        currsum = currsum * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            return currsum;
        }

        int left = find(root->left, currsum);
        int right = find(root->right, currsum);

        return left + right;
    }
    int sumNumbers(TreeNode* root) { return find(root, 0); }
};