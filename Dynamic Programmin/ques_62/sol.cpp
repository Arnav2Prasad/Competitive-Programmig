#include <vector>
#include <iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2D dp vector initialized with 1
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));

        // Fill the dp table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        // The bottom-right corner will have the answer
        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;
    int m = 3;
    int n = 7;
    std::cout << "Number of unique paths: " << sol.uniquePaths(m, n) << std::endl;
    return 0;
}
