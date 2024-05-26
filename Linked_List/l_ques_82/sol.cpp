
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        // Create a dummy node that points to the head of the list
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy; // Pointer to the node before the current sequence of duplicates

        while (head != nullptr) {
            // If it's a beginning of duplicates sequence, skip all duplicates
            if (head->next != nullptr && head->val == head->next->val) {
                // Move head until the end of duplicates sequence
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                // Skip all duplicates
                prev->next = head->next;
            } else {
                // Otherwise, move predecessor
                prev = prev->next;
            }
            // Move forward
            head = head->next;
        }

        // Return the modified list, skipping the dummy node
        ListNode* newHead = dummy->next;
        delete dummy; // Free the memory allocated for the dummy node
        return newHead;
    }
};


