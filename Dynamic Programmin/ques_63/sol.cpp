class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n = o.size();  // number of rows
        int m = o[0].size();  // number of columns

        vector<int> dp(m, 0);
        dp[0] = o[0][0] == 1 ? 0 : 1;  // Initialize the starting point

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (o[i][j] == 1) {
                    dp[j] = 0;  // If there's an obstacle, no paths go through this cell
                } else if (j > 0) {
                    dp[j] = (dp[j] + dp[j - 1]);  // Update the number of paths to this cell
                }
            }
        }

        return dp[m - 1];  // The number of unique paths to the bottom-right corner
    }
};
