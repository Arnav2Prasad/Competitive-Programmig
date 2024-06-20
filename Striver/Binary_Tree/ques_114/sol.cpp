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
    void flatten(TreeNode* root) {
        if (!root) return;
        
        flatten(root->left);    // Flatten the left subtree
        flatten(root->right);   // Flatten the right subtree
        
        // Store the right subtree in a temporary variable
        TreeNode* temp = root->right;
        
        // Attach the flattened left subtree to the right of the current root
        root->right = root->left;
        root->left = nullptr;
        
        // Find the end of the current flattened subtree and attach the original right subtree
        TreeNode* curr = root;
        while (curr->right != nullptr) {
            curr = curr->right;
        }
        curr->right = temp;
    }
};
