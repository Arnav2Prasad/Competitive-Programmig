
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> values;

    // Traverse the list and collect values in a vector
    ListNode* current = head;
    while (current != NULL) {
        values.push_back(current->val);
        current = current->next;
    }

    int n = values.size();
    int maxTwinSum = 0;

    // Calculate twin sums and find the maximum
    for (int i = 0; i < n / 2; ++i) {
        int twinSum = values[i] + values[n - 1 - i];
        if (twinSum > maxTwinSum) {
            maxTwinSum = twinSum;
        }
    }

    return maxTwinSum;

    }
};

