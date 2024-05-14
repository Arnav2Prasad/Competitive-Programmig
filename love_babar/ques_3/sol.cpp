class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
    int left = 0, right = n - 1, curr = 0;

    while (curr <= right) {
        if (nums[curr] == 0) {
            swap(nums[left], nums[curr]);
            left++;
            curr++;
        } else if (nums[curr] == 2) {
            swap(nums[curr], nums[right]);
            right--;
        } else {
            curr++;
        }
    }
    }
};
