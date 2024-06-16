class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();  // rows
        // int m = matrix[0].size();  // cols

        // vector<vector<int>> dp(n , vector<int>(m,0));

        vector<int> prev(n,0);
        vector<int> curr(n,0);

        for (int j=0;j<n;j++){
            // dp[0][j] = matrix[0][j];
            prev[j] = matrix[0][j];
        }
        curr = prev;
        int r_diag = INT_MAX;
        int l_diag = INT_MAX;
        int up = 0;

        for (int i=1;i<n;i++){
            for (int j=0;j<n;j++){
                r_diag = INT_MAX;
                l_diag = INT_MAX;
                // int up = dp[i-1][j];
                up = prev[j];
                if (j-1 >= 0){
                    // l_diag = dp[i-1][j-1];
                    l_diag = prev[j-1];
                }
                
                if (j+1 < n){   
                    // r_diag = dp[i-1][j+1];
                    r_diag = prev[j+1];
                }
                // dp[i][j] = min({up,l_diag, r_diag}) + matrix[i][j];
                int  g= min(up,l_diag);
                curr[j] = min(g,r_diag) + matrix[i][j];
            }
            prev=curr;
            // curr={};
        }
        // int min1 = INT_MAX;

        // for (int i=0;i<m;i++){
        //     if (dp[n-1][i] < min1){
        //         min1 = dp[n-1][i];
        //     }
        // }
        return *min_element(curr.begin(),curr.end());
        
        
    }
};
