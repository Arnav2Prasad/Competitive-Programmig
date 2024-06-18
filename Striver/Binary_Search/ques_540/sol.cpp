class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size()==1){
            return nums[0];
        }
        int start=1;
        int end = nums.size()-1;
        int mid=0;

        if (nums[0] != nums[1]){
            return nums[0];
        }
        if (nums[end] != nums[end-1]){
            return nums[end];
        }
        end--;

        while (start<=end){
            mid = (start+end)/2;
            if (nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
                return nums[mid];
            }
            else if (nums[mid]==nums[mid-1]){
                if ((mid) %2 == 1){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            else if (nums[mid]==nums[mid+1]){
                if ((mid) %2 == 0){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
        
    }
};
