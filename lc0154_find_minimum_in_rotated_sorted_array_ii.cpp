// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    int findMin(vector<int>& nums) {       
        int lo=0, hi=nums.size()-1;
        
        while (lo < hi) {
            int mi = lo + (hi-lo) / 2;
            
            if (nums[mi] > nums[hi])  
                lo = mi + 1;
            else if (nums[mi] < nums[lo])  
                hi = mi, lo++;
            else  
                hi--;
        }       
        return nums[lo];
    }
};