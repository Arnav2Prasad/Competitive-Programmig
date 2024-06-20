class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || n <= 0) {
            return head;
        }
        
        // Use dummy node to handle edge case of removing head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move fast pointer n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            if (fast == nullptr) {
                delete dummy; // Clean up dummy node
                return head; // If n is greater than the length of the list
            }
            fast = fast->next;
        }
        
        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Delete the nth node from the end
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        
        ListNode* result = dummy->next; // Updated head
        delete dummy; // Clean up dummy node
        
        return result;
    }
};
