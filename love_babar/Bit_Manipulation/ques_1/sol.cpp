class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
    while (n) {
        count += n & 1; // Add 1 to count if the LSB is 1
        n >>= 1;        // Shift the number to the right by 1
    }
    return count;
    }
};
