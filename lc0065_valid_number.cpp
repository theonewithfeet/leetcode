// https://leetcode.com/problems/valid-number/

class Solution {
public:
    bool isNumber(string s) {
        bool sign=false, point=false, expo=false, digit=false;
        
        for (auto ch : s) {
            switch (ch) {
                case '+':
                case '-':
                    if (sign || digit || point) return false;
                    sign = true;
                    break;
                case '0': case '1': case '2': case '3': case '4':
                case '5': case '6': case '7': case '8': case '9':
                    digit = true;
                    break;
                case '.':
                    if (point || expo) return false;
                    point = true;
                    break;
                case 'e': case 'E':
                    if (expo || !digit) return false;
                    sign = point = digit = false;
                    expo = true;
                    break;
                default:
                    return false;
            };
        }
        return digit;        
    }
};