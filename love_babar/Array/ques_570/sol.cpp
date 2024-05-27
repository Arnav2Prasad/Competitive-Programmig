
class Solution {
public:
    int distributeCandies(vector<int>& c) {
        set<int> a;
        for (int i=0;i<c.size() ; i++){
            a.insert(c[i]);
        }
        if (c.size() / 2 < a.size()){
            return c.size()/2;
        }
        else{
            return a.size();
        }
    }
};


