class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> r(nums.size()+1,3);
        r[0]=1;
        for (int i=0;i<nums.size();i++){
            for (int j=0;j<=nums[i];j++){
                if ((j + i) <= nums.size() && r[i] == 1){
                    r[j + i]=1;
                }
            }
        }
        return r[nums.size()-1]==1;
    }
};



------------------------------------------------
    CHATGPT SOL

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;  // To track the maximum index we can reach
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (i > maxReach) {
                // If the current index is greater than the maximum reachable index,
                // we can't reach this point
                return false;
            }
            // Update the maximum reachable index
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= n - 1) {
                // If we can reach or exceed the last index, return true
                return true;
            }
        }
        return maxReach >= n - 1;
    }
};
