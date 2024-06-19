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
    int help(TreeNode* root , int& maxi){
        if (!root){
            return 0;
        }
        // if (maxi<0){
        //     return 0;   
        // }
        int lmaxi =max(0,help(root->left,maxi));
        int rmaxi = max(0 , help(root->right,maxi));
        maxi = max(maxi , lmaxi+rmaxi+root->val);
        return max(lmaxi,rmaxi)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if (!root){
            return 0;
        }

        if (!root->left && !root->right){
            return root->val;
        }
        int maxi=INT_MIN;
        help(root,maxi);
        return maxi;

        
    }
};
