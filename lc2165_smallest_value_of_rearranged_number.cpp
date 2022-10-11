// https://leetcode.com/problems/smallest-value-of-the-rearranged-number/

class Solution {
public:
    long long smallestNumber(long long num) {
        if (abs(num) > 9) {
            string str = to_string(abs(num));

            if (num < 0) {
                sort(str.begin(),str.end(),greater<>());
                num = stol(str) * -1;
            }
            else {
                sort(str.begin(),str.end());
                int i=0;
                while (str[i] == '0')
                    i++;
                if (i>0)
                    swap(str[0],str[i]);
                num = stol(str);
            }
        }
        return num;
    }
};