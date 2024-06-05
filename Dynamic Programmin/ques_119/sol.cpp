class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> r;
        for (int i=0;i<=rowIndex ;i++){
            if (i==0){
                r.push_back({1});
            }else{
                vector<int> z;
                for (int j=0;j<r[i-1].size();j++){
                    if (j==0){
                        z.push_back(1);
                    }
                    else{
                        z.push_back(r[i-1][j] + r[i-1][j-1]);
                    }
                    // z.push_back(r[i-1][j] + r[i-1][j-1]);
                }
                z.push_back(1);
                r.push_back(z);
            }
        }
        return r[rowIndex];
    }
};
