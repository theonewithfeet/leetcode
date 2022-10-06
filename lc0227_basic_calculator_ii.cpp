// https://leetcode.com/problems/basic-calculator-ii/

class Solution {
public:
    int calculate(string& s) {
        int last=0, curr=0, result=0, op='+', n=s.size();
        for (int i=0; i<n; i++) {
            char ch = s[i];
            if (isdigit(ch))
                curr = curr*10+(ch-'0');
            if (!isdigit(ch) && ch != ' ' || i==n-1) {
                if (op == '*') 
                    last *= curr;
                else if (op == '/')
                    last /= curr;
                else {
                    result += last;
                    last = (op == '+') ? curr : -curr;
                }
                op = ch;
                curr = 0;
            }
        }
        return result + last;
    }
};