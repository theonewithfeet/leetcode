// https://leetcode.com/problems/largest-number-at-least-twice-of-others/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maximum=INT_MIN, second=INT_MIN, index=-1;
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > maximum) {
                second  = maximum;
                maximum = nums[i];
                index   = i;
            }
            else if (nums[i] > second)
                second = nums[i];
        }
        return second <= maximum/2 ? index : -1;
    }
};