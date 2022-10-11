// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo=0, hi=numbers.size()-1;
        
        while (lo < hi) {
            int value = numbers[lo] + numbers[hi];
            
            if (value == target)
                break;
            if (value < target)
                lo++;
            else
                hi--;
        }
        return {lo+1,hi+1};
    }
};