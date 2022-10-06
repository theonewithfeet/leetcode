// https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0, prev=0;
        for (auto num : nums) {
            count += max(0,prev-num+1);
            prev   = max(num,prev+1);
        }
        return count;
    }
};