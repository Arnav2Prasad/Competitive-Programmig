#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& v) {
        if (v.empty()){
            if (n==1){
                return 1;
            }
            return -1;
        }
        vector<int> p(n+1,0);
        for (int i=0;i<v.size();i++){
            p[v[i][0]]=-5;
            if (p[v[i][1]] !=-5){
                p[v[i][1]]++;
            }
        }
        for (int i=0;i<p.size();i++){
            if (p[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};
