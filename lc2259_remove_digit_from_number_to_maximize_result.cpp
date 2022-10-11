// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/

class Solution {
public:
    string removeDigit(string number, char digit) {
        string result;
        for (int i=number.size()-1; i>=0; i--)
            if (number[i] == digit) {
                string value = number.substr(0,i) + number.substr(i+1);
                result = max(result,value);
            }
        return result;
    }
};