int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	// Sort arrival and departure arrays
    std::sort(arr, arr + n);
    std::sort(dep, dep + n);

    // Initialize variables
    int platforms_needed = 0;
    int max_platforms = 0;
    int i = 0; // Pointer to arrival array
    int j = 0; // Pointer to departure array

    // Traverse arrival and departure arrays
    while (i < n && j < n) {
        // If the next event is an arrival, increment platform count
        if (arr[i] < dep[j]) {
            platforms_needed++;
            i++;
            // Update max_platforms if needed
            max_platforms = std::max(max_platforms, platforms_needed);
        } else { // If the next event is a departure, decrement platform count
            platforms_needed--;
            j++;
        }
    }

    return max_platforms;
    }
