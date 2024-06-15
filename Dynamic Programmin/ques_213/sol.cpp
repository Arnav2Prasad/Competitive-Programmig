class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // Helper function to solve the linear house robber problem
        auto rob_linear = [](const vector<int>& nums, int start, int end) -> int {
            int prev2 = 0, prev1 = 0;
            for (int i = start; i <= end; ++i) {
                int current = max(prev1, prev2 + nums[i]);
                prev2 = prev1;
                prev1 = current;
            }
            return prev1;
        };

        // Calculate the two scenarios
        int rob_first_to_last_but_one = rob_linear(nums, 0, n - 2);
        int rob_second_to_last = rob_linear(nums, 1, n - 1);

        // Return the maximum of the two scenarios
        return max(rob_first_to_last_but_one, rob_second_to_last);
    }
};
