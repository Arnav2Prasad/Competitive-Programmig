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
    bool help(TreeNode* root,int* height){
        if (root==NULL){
            return 1;
        }
        int lh=0;
        int rh=0;
        if (help(root->left,&lh)==0){
            return 0;
        }
        if (help(root->right,&rh)==0){
            return 0;
        }
        *height = max(lh,rh) + 1;
        if (abs(lh-rh) <= 1){
            return 1;
        }
        return 0;

    }
    bool isBalanced(TreeNode* root) {
        if (root==NULL){
            return 1;
        }
        int height=0;
        return help(root,&height);
        
    }
};
