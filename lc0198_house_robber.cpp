// https://leetcode.com/problems/house-robber/

class Solution {
    int dp[1+100];
    
    int maxSum(vector<int>& nums,int i) {
        if (i >= nums.size()) return 0;
        
        if (dp[i] == -1) 
            dp[i] = max(maxSum(nums,i+1),nums[i]+maxSum(nums,i+2));
        
        return dp[i];
    }
public:
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return maxSum(nums,0);
    }
};