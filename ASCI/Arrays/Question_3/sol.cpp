vector<int> valueEqualToIndex(int arr[], int n) {
	    // code here
	    vector<int> v;
	    for (int i=0;i<n;i++){
	        if (arr[i]==(i+1)){
	            v.push_back(arr[i]);
	        }
	    }
	   // if (v=={}){
	   //     retur
	   // }
	    return v;
	}
