class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;

        for (int i = 1; i <= n; i++) {

            string str = to_string(i);

            bool isValid = true;

            bool isDifferent = false;

            string rotatedStr = "";

            for (char c : str) {

                if (c == '0' || c == '1' || c == '8') {

                    rotatedStr += c;

                } else if (c == '2') {

                    rotatedStr += '5';

                    isDifferent = true;

                } else if (c == '5') {

                    rotatedStr += '2';

                    isDifferent = true;

                } else if (c == '6') {

                    rotatedStr += '9';

                    isDifferent = true;

                } else if (c == '9') {

                    rotatedStr += '6';

                    isDifferent = true;

                } else {

                    isValid = false;

                    break;

                }

            }

            if (isValid && isDifferent) {

                count++;

            }

        }

        return count;
    }
};
