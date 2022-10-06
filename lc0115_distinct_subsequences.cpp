// https://leetcode.com/problems/distinct-subsequences/

class Solution {
    int dp[1000][1000];
    int count(string& s,string& t,int i,int j) {
        if (j == t.size())
            return 1;
        if (i == s.size())
            return 0;
        if (dp[i][j] == -1) {
            if (s[i] == t[j])
                dp[i][j] = count(s,t,i+1,j+1) + count(s,t,i+1,j);
            else
                dp[i][j] = count(s,t,i+1,j);
        }
        return dp[i][j];
    }
public:
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return count(s,t,0,0);
    }
};