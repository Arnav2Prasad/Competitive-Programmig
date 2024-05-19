class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> ans(n + 1, 0);

    // Iterate from 1 to n and calculate the number of 1's in binary representation
    for (int i = 1; i <= n; ++i) {
        ans[i] = ans[i >> 1] + (i & 1);
    }

    return ans;
    }
};
