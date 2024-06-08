class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        
        int result = 10; // All one-digit numbers
        int uniqueDigits = 9;
        int availableNumber = 9;
        
        for (int i = 2; i <= n && availableNumber > 0; ++i) {
            uniqueDigits = uniqueDigits * availableNumber;
            result += uniqueDigits;
            --availableNumber;
        }
        
        return result;
    }
};
