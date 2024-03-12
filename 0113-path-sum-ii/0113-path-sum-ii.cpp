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

    private:
    void solve(vector<vector<int>>& ans , vector<int>&v , TreeNode* root , int target, bool& is_done, TreeNode* prev, int& sum )
    {
        if(root == NULL)
        {
            if(sum == target && (prev->left == NULL && prev->right == NULL) && is_done)
            {
                ans.push_back(v);
            }
            return;
        }
        is_done = true;
        sum += root->val;
        v.push_back(root->val);

        //inorder transversal

        solve(ans , v , root->left , target , is_done, root , sum);
        is_done = false;
        solve(ans , v , root->right , target , is_done, root , sum);

        sum = sum - root->val;
        v.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>v;
        int sum=0;
        bool is_done = true;

        if(root == NULL) return ans;
        if(root->val == targetSum && ((root->right == NULL && root->left != NULL) || (root->right != NULL && root->left == NULL))) return ans;

        TreeNode* prev = NULL;

        solve(ans , v , root, targetSum , is_done, prev, sum);

        return ans;
        
    }
};