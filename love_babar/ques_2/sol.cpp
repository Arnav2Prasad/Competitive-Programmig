#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    // Min-heap to store the k largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Iterate through the array
    for (int num : nums) {
        // If the heap size is less than k, push the element
        if (minHeap.size() < k) {
            minHeap.push(num);
        } else {
            // If the current element is larger than the smallest element in the heap,
            // replace the smallest element with the current element
            if (num > minHeap.top()) {
                minHeap.pop();
                minHeap.push(num);
            }
        }
    }

    // The top element of the heap will be the kth largest element
    return minHeap.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << "Kth largest element: " << findKthLargest(nums, k) << endl;
    return 0;
}
