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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root){
            return {};
        }
        if (!root->left && !root->right){
            return {{root->val}};
        }
         map<int, map<int, vector<int>>> nodes;
        // Queue to perform BFS. Stores nodes along with their column and row information
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int col = p.second.first;
            int row = p.second.second;
            nodes[col][row].push_back(node->val);

            if (node->left) {
                q.push({node->left, {col - 1, row + 1}});
            }
            if (node->right) {
                q.push({node->right, {col + 1, row + 1}});
            }
        }

        vector<vector<int>> result;
        for (auto& col : nodes) {
            vector<int> columnNodes;
            for (auto& row : col.second) {
                sort(row.second.begin(), row.second.end());
                columnNodes.insert(columnNodes.end(), row.second.begin(), row.second.end());
            }
            result.push_back(columnNodes);
        }

        return result;

        
    }
};
