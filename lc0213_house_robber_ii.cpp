// https://leetcode.com/problems/house-robber-ii/

class Solution {
    int dp[1+100][2];
    int maxLoot(vector<int>& nums, int i, bool zero) {
        if (i>=nums.size() || zero && i==nums.size()-1) return 0;
        
        if (dp[i][zero] == -1)
            dp[i][zero] = max(maxLoot(nums,i+1,zero),nums[i]+maxLoot(nums,i+2,zero));
        
        return dp[i][zero];
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        memset(dp,-1,sizeof(dp));
        return max(maxLoot(nums,0,1),maxLoot(nums,1,0));
    }
};