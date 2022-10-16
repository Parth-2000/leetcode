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
    bool solve(TreeNode* n1, TreeNode* n2){
        if(n1 == NULL || n2 == NULL) return n1 == n2;
        if(n1->val != n2->val) return false;
        return solve(n1->left, n2->right) && solve(n1->right, n2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL or (root->left == NULL && root->right == NULL)) return true;
        return solve(root->left, root->right);
    }
};