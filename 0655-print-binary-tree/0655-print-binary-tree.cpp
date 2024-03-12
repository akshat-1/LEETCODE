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
private:
    int get_height(TreeNode* root, int h) {
        if (root == NULL) {
            return h;
        }

        int left = get_height(root->left, h + 1);
        int right = get_height(root->right, h + 1);

        h = max(left, right);

        return h;
    }

    void solve(TreeNode* root, vector<vector<string>>& res, int curr_row,
               int low, int high) {
        if (root == NULL)
            return;

        int mid = low + (high - low) / 2;

        res[curr_row][mid] = to_string(root->val);

        solve(root->left, res, curr_row + 1, low, mid - 1);
        solve(root->right, res, curr_row + 1, mid + 1, high);
    }

public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = -1;
        int height = get_height(root, h);
        int m = height + 1;
        int n = pow(2, height + 1) - 1;

        vector<vector<string>> res(m, vector<string>(n, ""));

        int low = 0;
        int high = n - 1;
        int curr_row = 0;
        solve(root, res, curr_row, low, high);

        return res;
    }
};