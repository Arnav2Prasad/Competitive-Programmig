/*

The provided code implements Floyd's Tortoise and Hare algorithm, a technique commonly used for cycle detection in linked lists. In this case, the array itself is treated as a representation of a linked list, where the value at each index points to the next index to jump to. Here's how the algorithm works:

	1. Phase 1: Finding Intersection Point:
   		--> Two pointers, `slow` and `fast`, are initialized to the first element of the array.
   		--> In a loop, `slow` moves one step at a time (`slow = nums[slow]`), while `fast` moves two steps at a time (`fast = nums[nums[fast]]`).
   		--> The loop continues until `slow` and `fast` meet at the same index. This indicates the presence of a cycle in the array.


	2. Phase 2: Finding Entrance to the Cycle:
   		--> After identifying that there's a cycle, we reset one of the pointers, `slow`, back to the first element of the array.
   		--> Now, both `slow` and `fast` move at the same pace, one step at a time.
   		--> Eventually, they meet at the entrance point of the cycle. This point is the duplicate number in the array.


The reason this algorithm works is rooted in its mathematical foundation. When there's a cycle, the two pointers will eventually meet within the cycle. By resetting one of the pointers and moving them at the same pace, they will meet exactly at the entrance point of the cycle, which is also the duplicate number in the array.

This approach solves the problem without modifying the original array (`nums`) and uses only constant extra space, fulfilling the requirements of the problem statement. It has a time complexity of O(n), where n is the length of the array, and a space complexity of O(1), making it efficient in terms of both time and space.

*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
    int fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Phase 2: Find the entrance to the cycle
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
    }
};
