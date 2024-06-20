class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(0); // Dummy head to facilitate merging
        ListNode* curr = dummyHead; // Pointer to build the merged list
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        
        // Attach remaining nodes from list1 or list2
        if (list1 != nullptr) {
            curr->next = list1;
        }
        if (list2 != nullptr) {
            curr->next = list2;
        }
        
        ListNode* mergedList = dummyHead->next;
        delete dummyHead; // Delete the dummy head
        
        return mergedList;
    }
};
