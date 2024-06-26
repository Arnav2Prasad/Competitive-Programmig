long long maxSubarraySum(int arr[], int n) {
        long long max_so_far = INT_MIN;
    long long max_ending_here = 0;

    for (int i = 0; i < n; ++i) {
        max_ending_here = max_ending_here + arr[i];

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }

    return max_so_far;

        // Your code here
    }
