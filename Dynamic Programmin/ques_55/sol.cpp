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
