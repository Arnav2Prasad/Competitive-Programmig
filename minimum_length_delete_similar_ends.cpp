//QUESTION : 1750
//MINIMUM LENGTH OF STRING AFTER DELETING SIMILAR ENDS
//LINK : https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05

class Solution {
public:
    int minimumLength(string s) {
        int max_len = s.length();
        int start = 0;
        char ch;
        int end = s.length() - 1;
        while (start < end) {
          if (s[start] == s[end]) {
            max_len -= 2;
            ch = s[start];
            start++;
            end--;
            while (start <= end && s[start] == ch) {
              start++;
              max_len -= 1;
            }
            while (start <= end && s[end] == ch) {
              end--;
              max_len -= 1;
            }
      
          } else {
            break;
          }
        }
      return max_len;
    }
};
