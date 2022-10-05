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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left=root;
            return node;
        }
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while(!q.empty()){
            int s = q.size();
            count++;
            for(int i = 0; i < s; i++){
                TreeNode* currNode = q.front();
                q.pop();
                if(count == depth-1){
                    TreeNode* leftNode = currNode->left;
                    currNode->left = new TreeNode(val);
                    currNode->left->left = leftNode;
                    TreeNode* rightNode = currNode->right;
                    currNode->right = new TreeNode(val);
                    currNode->right->right = rightNode;
                }
                if(currNode->left != NULL){
                    q.push(currNode->left);
                }
                if(currNode->right != NULL){
                    q.push(currNode->right);
                }
            }
        }
        return root;
    }
};