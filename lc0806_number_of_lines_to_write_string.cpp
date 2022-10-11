// https://leetcode.com/problems/number-of-lines-to-write-string/

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines=1, width=0;
        
        for (auto ch : s) {
            width += ch = widths[ch-'a'];             
            if (width > 100) {
                lines += 1;
                width  = ch;
            }
        }
        return {lines,width};
    }
};