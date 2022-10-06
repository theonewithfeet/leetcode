// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/ 

class Solution {
    int solve(int k, vector<int>& prices,int i,vector<vector<int>>& dp) {
        if (i==prices.size() || k==0) 
            return 0;
        
        if (dp[i][k] == -1) {
            int xact = solve(k-1,prices,i+1,dp) + ((k%2) ? prices[i] : -prices[i]);
            int hold = solve(k,prices,i+1,dp);
            
            dp[i][k] = max(xact,hold);
        }
        return dp[i][k];
    } 
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(k*2+1,-1));
        return solve(k*2,prices,0,dp);
    }
};