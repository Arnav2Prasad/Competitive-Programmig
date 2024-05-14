class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        // cout << "string length is : " << end << endl;
        while (start < end){
            if ( ! ((s[start]>='A' && s[start]<='Z')  || (s[start]>='a' && s[start]<='z') || 
            (s[start]>='0' && s[start]<='9')  )){
                // cout << "s[start] " << s[start] << endl;
                // cout << "--------------" << endl;
                start++;
            }
            else if ( ! ((s[end]>='A' && s[end]<='Z')  || (s[end]>='a' && s[end]<='z') || (s[end]>='0' && s[end]<='9') )){
            //    cout << "s[end] " << s[end] << endl;
                // cout << "--------------" << endl;
                end--;
                //cout << "s[start] " << s[start] << endl;
            }
            else if (s[start] >= 'A' && s[start] <= 'Z'){
                s[start] += 32;
            }
            else if (s[end] >= 'A' && s[end] <= 'Z'){
                s[end] += 32;
            }
            else if (s[start] != s[end]){
                // cout << "exiting ----" << endl;
                // cout << "s[start] : " << start << " : " << s[start] << endl;
                // cout << "s[end] : " << end << " : " << s[end] << endl;
                return 0;
            }
        else if(s[start] == s[end]){
            start++;
            end--;
}
        }
        return 1;
    }
};



