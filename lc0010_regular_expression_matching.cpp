// https://leetcode.com/problems/regular-expression-matching/

class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        if (p.size() == 0) 
            return s.size() == 0;
        
        bool found = s.size() > 0 && (s[0] == p[0] || p[0] == '.');
        
        if (p.size() >= 2 && p[1] == '*') 
            return isMatch(s,p.substr(2)) || (found && isMatch(s.substr(1),p));
        
        return found && isMatch(s.substr(1),p.substr(1));
    }
};