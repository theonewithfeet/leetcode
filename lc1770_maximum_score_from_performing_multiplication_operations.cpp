// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

class Solution {
    int dp[1000][1000][2];
    
    int maxScore(int lo,int i,vector<int>& nums,vector<int>& muls) {
        if (i == muls.size()) return 0;
        
        if (dp[lo][i][1]) return dp[lo][i][0];
        
        dp[lo][i][1] = 1;
        
        int hi = nums.size()-1 - (i-lo);
        
        int left  = maxScore(lo+1,i+1,nums,muls) + nums[lo]*muls[i];
        int right = maxScore(lo,i+1,nums,muls)   + nums[hi]*muls[i];
        
        return dp[lo][i][0] = max(left,right);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        memset(dp,0,sizeof(dp));        
        return maxScore(0,0,nums,multipliers);
    }
};