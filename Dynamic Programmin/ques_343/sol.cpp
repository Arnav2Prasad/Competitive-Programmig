class Solution {
public:
    int integerBreak(int n) {
        if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 2;

    // We keep dividing n into 3 as much as possible.
    int product = 1;
    while (n > 4) {
        product *= 3;
        n -= 3;
    }

    // Remaining n is now 4 or less, and we multiply it to the product.
    product *= n;

    return product;
        
    }
};
