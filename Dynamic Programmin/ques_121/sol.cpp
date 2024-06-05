class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=INT_MAX;
        int max=INT_MIN;
        int min_idx=0;
        int diff=0;
        for (int i : prices){
            if (min > i){
                min = i;
                min_idx = i;
                max=INT_MIN;
            }
            if (max<i){
                max=i;
                if (max-min > diff){
                    diff = max-min;
                }
            }
        }
        return diff;
    }
};
