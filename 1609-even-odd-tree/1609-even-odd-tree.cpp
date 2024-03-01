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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int f = 0;
        while(!q.empty()){
            int s = q.size();
            int m = -1;
            for(int i = 0; i < s; i++){
                TreeNode* node = q.front();
                q.pop();
                if(m == -1){
                    if(f == 0){
                        if(node->val & 1) m = node->val;
                        else return false;
                    }else{
                        if(node->val & 1) return false;
                        else m = node->val; 
                    }
                }else{
                    if(f == 0){ // Even
                        if(node->val & 1){
                            if(node->val > m){
                                m = node->val;
                            }else{
                                return false;
                            }
                        }else{
                            return false;
                        }   
                    }else{
                        if(node->val & 1){
                            return false;
                        }else{
                            if(node->val < m){
                                m = node->val;
                            }else{
                                return false;
                            }
                        }   
                    }
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            f = !f;
        }
        return true;
    }
};