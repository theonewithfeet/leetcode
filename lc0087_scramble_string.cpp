// https://leetcode.com/problems/scramble-string/

class Solution {
    bool isScramble(const string& s1,const string& s2,unordered_map<string,int>& dp) {
        int n=s1.size();       
        if (n == 1) return s1 == s2;
        if (s1 == s2) return true;
        
        string key=s1+":"+s2;
        
        if (! dp.count(key)) {       
            for (int i=1; i<=n-1; i++) {
                string a1=s1.substr(0,i),b1=s1.substr(i);            

                if ((isScramble(a1,s2.substr(0,i),dp) && isScramble(b1,s2.substr(i),dp)) ||
                    (isScramble(a1,s2.substr(n-i),dp) && isScramble(b1,s2.substr(0,n-i),dp))) {
                    dp[key] = true;
                    break;
                }
            }
        }
        return dp[key];
    }
public:
    bool isScramble(string s1, string s2) {
        unordered_map<string,int> dp;        
        return isScramble(s1,s2,dp);
    }
};