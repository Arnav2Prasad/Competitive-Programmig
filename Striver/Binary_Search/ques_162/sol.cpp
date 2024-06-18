class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size()==1){
            return 0;
        }
        int start=1;
        int end=nums.size()-1;
        int mid=0;

        if (nums[0] > nums[1]){
            return 0;
        }
        if (nums[end] > nums[end-1]){
            return end;
        }
        end--;

        while (start <= end){
            mid = (start+end)/2;
            if (nums[mid] > nums[mid-1] && nums[mid]> nums[mid+1]){
                return mid;
            }
            if (nums[mid] >= nums[mid-1] && nums[mid] <= nums[mid+1]){
                start = mid+1;
            }
            else if(nums[mid] < nums[mid-1]){
                end=mid-1;
            }
            else if(nums[mid] > nums[mid+1]){
                end = mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return 1;
        
    }
};
