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
//     TreeNode* buildTree(vector<int> preorder , int pre_start , int pre_end , vector<int> inorder , int in_start , int in_end , map<int,int> in_map){
//         if (pre_start > pre_end || in_start > in_end){
//             return NULL;
//         }
//         TreeNode* root = new TreeNode(preorder[pre_start]);

//         int in_root = in_map[root->val];
//         int nums_left = in_root - in_start;

//         root->left = buildTree(preorder,pre_start+1,pre_start+nums_left,inorder,in_start,in_root-1,in_map);
//         root->right = buildTree(preorder,pre_start+nums_left+1,pre_end,inorder,in_root+1,in_end,in_map);

//         return root;


//     }
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         map<int,int> inMap;
//         for (int i=0;i<inorder.size();i++){
//             inMap[inorder[i]]=i;
//         }
//         TreeNode* root = buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
//         return root;
        
//     }
// };
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map to store the index of each element in inorder array
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        
        // Start recursion
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorder_map);
    }
    
private:
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                              vector<int>& inorder, int inStart, int inEnd,
                              unordered_map<int, int>& inorder_map) {
        // Base case
        if (preStart > preEnd || inStart > inEnd) {
            return NULL;
        }
        
        // The first element in preorder is the root
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        
        // Find the root index in inorder
        int inRootIndex = inorder_map[rootVal];
        
        // Number of elements in the left subtree
        int leftSubtreeSize = inRootIndex - inStart;
        
        // Recursively build the left and right subtree
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSubtreeSize,
                                     inorder, inStart, inRootIndex - 1, inorder_map);
        root->right = buildTreeHelper(preorder, preStart + leftSubtreeSize + 1, preEnd,
                                      inorder, inRootIndex + 1, inEnd, inorder_map);
        
        return root;
    }
};
