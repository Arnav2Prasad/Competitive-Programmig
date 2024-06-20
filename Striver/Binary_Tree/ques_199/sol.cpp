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
    void help(TreeNode* root, int level , vector<int>& v){
        if (!root){
            return;
        }
        if (level==v.size()){
            v.push_back(root->val);
        }
        help(root->right,level+1,v);
        help(root->left,level+1,v);

    }
    vector<int> rightSideView(TreeNode* root) {
        if (!root){
            return {};
        }
        if (!root->right && !root->left){
            return {root->val};
        }
        vector<int> v;
        help(root,0,v);
        return v;
    }
};
