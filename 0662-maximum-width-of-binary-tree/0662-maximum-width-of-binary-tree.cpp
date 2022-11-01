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
    int widthOfBinaryTree(TreeNode* root) {
    if(root==NULL) return 0;
    int width=0;
    queue<pair<TreeNode*, int>>q;
    q.push({root, 0});
    while(!q.empty()){
        int s=q.size();
        int l=q.back().second, f=q.front().second;
        for(int i=0; i<s; i++){
            root=q.front().first;
            int ind=q.front().second-l;
            q.pop();
            if(root->left!=NULL){q.push({root->left, ind*2+1});}
            if(root->right!=NULL){q.push({root->right, ind*2+2});}
        }
        width=max(width, l-f+1);
    }
    return width;
    }
};