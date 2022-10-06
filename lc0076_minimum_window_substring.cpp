// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        int chars[128];
        int finds[128];
        string result;
                
        memset(chars,0,sizeof(chars));        
        memset(finds,0,sizeof(finds));        
        for (auto ch : t) chars[ch] += 1;
        
        int fast=0, slow=0, count=0, target=t.size(), mlen=INT_MAX;
        
        while (fast < s.size()) {
            auto ch = s[fast];
            
            if (chars[ch]) {
                finds[ch] += 1;               
                if (finds[ch] <= chars[ch]) count++;                
            } 
            if (count >= target) {
                while (chars[s[slow]] == 0 || finds[s[slow]] > chars[s[slow]]) {
                    finds[s[slow]] -= 1;
                    slow++;
                }
                if (fast-slow+1 < mlen) {
                    mlen = fast-slow+1;
                    result = s.substr(slow,mlen);
                }
            }
            fast++;
        }
        return result;
    }
};

