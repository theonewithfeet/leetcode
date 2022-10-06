// https://leetcode.com/problems/single-number-iii/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long axb=0;
        for (auto num : nums) axb ^= num;
        
        int lsb=int((axb & (axb-1)) ^ axb);
        
        int a=0, b=0;        
        for (auto num : nums)
            (num & lsb) ? a ^= num : b ^= num;
        
        return {a,b};
    }
};