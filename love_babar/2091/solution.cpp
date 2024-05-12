#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int max(int a , int b){
        if (a>b){
            return a;
        }
        return b;
    }
    int minimumDeletions(vector<int>& nums) {
        if (nums.size()==1){
            return 1;
        }
        if (nums.size()==2){
            return 2;
        }
        int min=INT_MAX;
        int max=INT_MIN;
        // int count=0;
        int min_pos = 0;
        int max_pos=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]>max){
                max = nums[i];
                max_pos = i;
            }
            if (nums[i] < min){
                min = nums[i];
                min_pos = i;
            }
        }
        int temp = nums.size()/2;
        int g = nums.size();
        if (min_pos >=  temp && max_pos >= temp){
            // return (g - max(min_pos , max_pos));
            if (min_pos > max_pos){
                return g - max_pos;
            }
            return g-min_pos;
        }
        if (min_pos <= temp && max_pos <= temp){
            // return max(min_pos , max_pos);
            if (min_pos > max_pos){
                return min_pos+1;
            }
            return max_pos+1;
        }
        // return min_pos + nums.size() - max_pos+1;
        if (min_pos > max_pos){
                // return nums.size()- min_pos + max_pos + 1;
                if (nums.size()- min_pos + max_pos + 1 > min_pos){
                    // min_pos
                    return g-max_pos;
                }
                return nums.size() - min_pos + max_pos + 1;
        }
        // return nums.size() - max_pos + min_pos + 1;
        if (nums.size() - max_pos + min_pos + 1 > max_pos+1 || nums.size() - max_pos + min_pos + 1 > g-min_pos){
            // return max_pos + 1;
            // return g-min_pos;
            if (max_pos + 1 > g-min_pos){
                return g-min_pos;
            }
            return max_pos + 1;
        }
        return nums.size() - max_pos + min_pos + 1;

    }
    
};
