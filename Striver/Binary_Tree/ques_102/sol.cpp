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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root==NULL){
            return {};
        }
        if (root->left == NULL && root->right == NULL){
            return {{root->val}};
        }
        vector<vector<int>>v;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> p={ };
        while (!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if (temp != NULL){
                p.push_back(temp->val);
                if (temp->left){
                    q.push(temp->left);
                }
                if (temp->right){
                    q.push(temp->right);
                }
            }
            if (temp==NULL){
                // q.push(NULL);
                if (!q.empty()) {
                    q.push(nullptr);  // Add marker for next level
                }
                v.push_back(p);
                p={};
            }
            
        }
        return v;
    }
};
