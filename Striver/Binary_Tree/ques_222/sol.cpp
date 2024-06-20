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
    int findLeftHeight(TreeNode* root){
        if (!root){
            return 0;
        }
        TreeNode* temp = root;
        int count=1;
        while (temp){
            temp=temp->left;
            count++;
        }
        return count;
    }
    int findRightHeight(TreeNode* root){
        if (!root){
            return 0;
        }
        TreeNode* temp = root;
        int count=1;
        while (temp){
            temp=temp->right;
            count++;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        if (!root){
            return 0;
        }
        if (!root->right && !root->left){
            return 1;
        }

        int lh = findLeftHeight(root->left);
        int rh = findRightHeight(root->right);

        if (lh==rh){
            return (1<<lh) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
        
    }
};
