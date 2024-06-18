class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int mid=0;
        int min1 = INT_MAX;

        while (start <= end){
            mid = (start+end)/2;
            if (nums[mid] < min1){
                min1 = nums[mid];
            }
            if (nums[start] <= nums[mid]){
                min1 = min(nums[start] , min1);
                start = mid+1;
                
            }
            else{
                min1 = min(min1 , nums[end]);
                end = mid-1;
                
            }
        }
        return min1;
        
    }
};
