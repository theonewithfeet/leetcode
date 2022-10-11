// https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution {
public:
    string fractionToDecimal(int n, int d) {
        int64_t num=n, den=d;
        num=abs(num), den=abs(den);
        
        string str;
        if (n && ((n<0)^(d<0))) str += '-';
        
        unordered_map<int64_t,int> rems;
        
        str += to_string(num/den);
        num %= den;
        
        if (num) str += '.';
        
        while (num != 0) {
            if (rems.count(num)) {
                str = str.substr(0,rems[num])+"("+str.substr(rems[num])+")";
                break;
            }
            rems[num] = str.size();
            num *= 10;
            str += to_string(num/den);
            num %= den;
        }
        return str;
    }
};