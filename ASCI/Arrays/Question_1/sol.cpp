vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        vector<int> v(2, 0);
    long long sum = 0;
    // int start = 0;
    int i=0;
    v[0]=0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        
        while (sum > s && v[0] < i) {
            sum -= arr[v[0]];
            ++v[0];
        }       
        
        if (sum == s) {
            v[0] = v[0]+1;  // Convert to 1-based index
            v[1] = i + 1;    // Convert to 1-based index
            return v;
        }
    }
    
    return {-1};  // No subarray found
    }
