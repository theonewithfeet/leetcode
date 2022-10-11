// https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
    bool isPalendrome(string& s,int i,int j) {
        while (i<j) 
            if (s[i++] != s[j--]) return false;
        return true;
    }
    int solve(string& s,int i,int j,vector<int>& dp) {
        if (i>=j || isPalendrome(s,i,j)) return 0;
        
        if (dp[i] < 0) {
            dp[i] = INT_MAX;
            for (int k=i; k<j; k++)
                if (isPalendrome(s,i,k))
                    dp[i] = min(dp[i],1+solve(s,k+1,j,dp));
        }
        return dp[i];
    }
public:
    int minCut(string s) {
        vector<int> dp(s.size()+1,-1);       
        return solve(s,0,s.size()-1,dp);
    }
};