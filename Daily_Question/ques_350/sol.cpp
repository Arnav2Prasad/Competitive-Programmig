class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin(),nums2.end());

        vector<int> v;

        int x = nums1.size();
        int y = nums2.size();

        int size = x > y ? x : y;

        int one=0;
        int two=0;

        while (one < x && two < y){
            if (nums1[one] == nums2[two]){
                v.push_back(nums1[one]);
                one++;
                two++;
            }
            else if(nums1[one] > nums2[two]){
                two++;
            }
            else{
                one++;
            }
        }
        return v;
        
    }
};
