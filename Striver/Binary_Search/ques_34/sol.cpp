class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==1){
            if (nums[0] == target){
                return {0,0};
            }
            else{
                return {-1,-1};
            }
        }
        int start=0;
        int end=nums.size()-1;
        int mid=0;

        while (start<=end){
            mid = (start+end)/2;
            if (nums[mid]<target){
                start=mid+1;
            }
            else if(nums[mid] > target){
                end = mid-1;
            }
            else{
                int temp = mid;
                while (mid-1 < end && mid >=1 && nums[mid-1]==target){
                    mid--;
                }
                while (temp+1 <= end && nums[temp+1]==target){
                    temp++;
                }
                return {mid,temp};
            }
        }
        return {-1,-1};
        
    }
};
