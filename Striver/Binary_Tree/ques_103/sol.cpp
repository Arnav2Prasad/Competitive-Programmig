#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel(levelSize);
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Determine the position to insert the node's value
                int index = leftToRight ? i : (levelSize - 1 - i);
                currentLevel[index] = node->val;
                
                // Push children into the queue
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            // After this level, reverse the direction
            leftToRight = !leftToRight;
            result.push_back(currentLevel);
        }

        return result;
    }
};
