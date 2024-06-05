class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;  // Base case for n = 0 or 1
        
        vector<int> dp(n + 1);
        dp[0] = 1;  // One way to stay at the ground
        dp[1] = 1;  // One way to reach the first step

        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];  // The recurrence relation
        }

        return dp[n]; 
    }
};
