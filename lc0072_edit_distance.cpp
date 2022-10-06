// https://leetcode.com/problems/edit-distance/

class Solution {
    int dp[501][501] = {{0}};
    
    int levenshtein(const string& s1, const string& s2) {
        int n=s1.size(), m=s2.size();
        dp[0][0] = 0;
        for (int i=1; i<=m; i++)
            dp[i][0] = dp[i-1][0] + 1;
        for (int j=1; j<=n; j++)
            dp[0][j] = dp[0][j-1] + 1;
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
                dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + (s1[j-1] == s2[i-1] ? 0 : 1)});

        return dp[m][n];
    }
    
public:
    int minDistance(string word1, string word2) { 
        return levenshtein(word1,word2);
    }
};
