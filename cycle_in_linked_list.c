/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
        return false; // If the list is empty or has only one node, there's no cycle
    }

    ListNode *slow = head; // Slow pointer moves one step at a time
    ListNode *fast = head->next; // Fast pointer moves two steps at a time

    while (slow != fast) { // Move until slow meets fast or fast reaches the end
        if (fast == NULL || fast->next == NULL) {
            return false; // If fast reaches the end of the list, there's no cycle
        }
        slow = slow->next; // Move slow one step forward
        fast = fast->next->next; // Move fast two steps forward
    }

    return true;
    }
};
