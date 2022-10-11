// https://leetcode.com/problems/number-of-good-pairs/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int good=0, vals[100+1]={0};
        
        for (int num : nums)
            good += vals[num]++;
        
        return good; 
    }
};