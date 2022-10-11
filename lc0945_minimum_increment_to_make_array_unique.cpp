// https://leetcode.com/problems/minimum-increment-to-make-array-unique/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int minimum=0, count=0;
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] < minimum) {
                count  += minimum - nums[i];
                nums[i] = minimum;
            }
            minimum = nums[i] += 1;
        }
        return count;
    }
};