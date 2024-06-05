class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 0) return 0;
        if (n == 1) return cost[0];

        // dp array to store the minimum cost to reach each step
        vector<int> dp(n + 1, 0);

        // Initial conditions
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Fill the dp array using the recurrence relation
        for (int i = 2; i <= n; ++i) {
            int costStep = (i == n) ? 0 : cost[i];
            dp[i] = costStep + min(dp[i - 1], dp[i - 2]);
        }

        // The answer will be the minimum cost to reach one step beyond the last step
        return dp[n];
    }
};
