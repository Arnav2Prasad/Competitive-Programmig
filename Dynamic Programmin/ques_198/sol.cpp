class Solution {
public:
    int rob(vector<int>& nums) {
        // code works 100% !!!

        // int n = nums.size();
        // if (n<=2){
        //     sort(nums.begin(),nums.end());
        //     return nums[n-1];
        // }
        // vector<int> dp(n+1,0);
        // dp[0]=0;
        // dp[1]=nums[0];
        // dp[2] = nums[1];
        // // dp[3] = nums[0] + nums[3];
        // int max1=INT_MIN;
        // if (dp[1] > dp[2]){
        //     max1=dp[1];
        // }
        // else{
        //     max1 = dp[2];
        // }
        
        // for (int i=3;i<=n;i++){
        //     dp[i] = max(dp[i-3] + nums[i-1] , dp[i-2] + nums[i-1]);
        //     if (dp[i] > max1){
        //         max1=dp[i];
        //     }
        // }
        // return max1;

        int n=nums.size();
        if (n<=0){
            return 0;
        }
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=nums[0];

        for (int i=2;i<=n;i++){
            dp[i] = max(dp[i-2] + nums[i-1] , dp[i-1]);
        }
        return dp[n];
        
        
    }
};
