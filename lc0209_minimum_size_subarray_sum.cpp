// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0, n=nums.size(), minlen=INT_MAX;
        
        long sum=0;
        
        for (int i=0; i<n; i++) {
            sum += nums[i];
            while (sum >= target && start<=i) {
                minlen = min(minlen,i-start+1);
                sum -= nums[start++];
            }
        }
        return minlen < INT_MAX ? minlen : 0;
    }
};