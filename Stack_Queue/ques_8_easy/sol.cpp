class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> s;
        
        // Traverse nums2 from the end to the beginning
        for (int i = nums2.size() - 1; i >= 0; --i) {
            // Maintain a stack of elements for which we need to find the next greater element
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            // If stack is not empty, the top element is the next greater element
            nextGreater[nums2[i]] = s.empty() ? -1 : s.top();
            // Push the current element onto the stack
            s.push(nums2[i]);
        }
        
        // Construct the result array for nums1
        vector<int> result(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            result[i] = nextGreater[nums1[i]];
        }
        
        return result;
    }
};
