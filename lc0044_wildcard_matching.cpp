// https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
   bool isMatch(string s, string p) {
        int i=0, j=0, istar=-1, jstar=-1, slen=s.size(), plen=p.size();

        while (i<slen) {
            if (j < plen && p[j] == '*') {
                istar = i;
                jstar = ++j;
            }
            else if (j < plen && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            }
            else if (istar >= 0) {
                i = ++istar;
                j = jstar;
            }
            else 
                return false; 
        }
        while (j < plen && p[j] == '*') j++;
    
        return i == slen && j == plen;
    }
};