/*
45.		JUMP GAME II

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

    0 <= j <= nums[i] and
    i + j < n

Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].


*/


class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0; // If the array has only 1 or 0 elements, no jumps needed
        
        int jumps = 0; // Initialize the count of jumps
        int curEnd = 0; // Initialize the end of the current jump
        int curFarthest = 0; // Initialize the farthest reachable position
        
        for (int i = 0; i < n - 1; ++i) {
            curFarthest = std::max(curFarthest, i + nums[i]); // Update the farthest reachable position
            
            if (i == curEnd) { // If the current position is the end of the current jump
                if (curFarthest <= i) return -1; // If we can't move forward, return -1 (impossible to reach the end)
                curEnd = curFarthest; // Update the end of the current jump
                jumps++; // Increment the count of jumps
            }
        }
        
        return jumps; // Return the count of jumps
    }
};

