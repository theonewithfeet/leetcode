// https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0, close=0, result=0;
        for (int i=0; i < s.size(); i++) {
            if (s[i] == '(')
                open++;
            else
                close++;
            if (open == close)
                result = max(result,2*open);
            else if (open < close)
                open = close = 0;
        }
        open = close = 0;
        for (int i=s.size()-1; i>=0; i--) {
            if (s[i] == '(')
                open++;
            else
                close++;
            if (open == close)
                result = max(result,2*open);
            else if (open > close)
                open = close = 0;
        }
        return result;
    }
};