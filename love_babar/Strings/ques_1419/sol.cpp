
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> count(5, 0); // counts for 'c', 'r', 'o', 'a', 'k'
        int maxFrogs = 0;
        int currentFrogs = 0;

        for (char c : croakOfFrogs) {
            if (c == 'c') {
                count[0]++;
                currentFrogs++;
                maxFrogs = max(maxFrogs, currentFrogs);
            } else if (c == 'r') {
                if (count[0] == 0) return -1;
                count[0]--;
                count[1]++;
            } else if (c == 'o') {
                if (count[1] == 0) return -1;
                count[1]--;
                count[2]++;
            } else if (c == 'a') {
                if (count[2] == 0) return -1;
                count[2]--;
                count[3]++;
            } else if (c == 'k') {
                if (count[3] == 0) return -1;
                count[3]--;
                currentFrogs--;
            } else {
                return -1; // invalid character
            }
        }

        // After processing, all frogs should have completed the "croak" sequence
        if (currentFrogs > 0 || count[0] > 0 || count[1] > 0 || count[2] > 0 || count[3] > 0) {
            return -1;
        }

        return maxFrogs;
    }
};
