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
    
    bool preOrder(TreeNode* n1, TreeNode* n2){
        if (n1 == NULL || n2 == NULL){
            return (n1 == n2); 
        } 
        return n1->val == n2->val && preOrder(n1->left, n2->left) && preOrder(n1->right, n2->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        return preOrder(p, q);
    }
};