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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q!=NULL ) return false;
        if(q== NULL && p != NULL) return false;
        if(p!= NULL && q!= NULL)
        {
            if(p->val != q->val) return false;
        }
        if(p == NULL && q == NULL) return true;

        bool is_left , is_right;
        is_left = isSameTree(p->left , q->left);
        is_right = isSameTree(p->right , q->right);

        if(is_left && is_right) return true;
        else return false;
        
    }
};