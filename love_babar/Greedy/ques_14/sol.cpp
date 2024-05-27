

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxSoFar = nums[0];
        int currentMax = nums[0];
        int currentMin = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            int num = nums[i];

            if (num < 0) std::swap(currentMax, currentMin);

            currentMax = std::max(num, currentMax * num);
            currentMin = std::min(num, currentMin * num);

            maxSoFar = std::max(maxSoFar, currentMax);
        }

        return maxSoFar;
    }
};
