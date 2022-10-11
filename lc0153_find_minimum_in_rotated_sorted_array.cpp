// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size(), lo=0, hi=n-1;
        
        while (lo < hi) {
            int mid = lo + (hi-lo) / 2;
            
            if (nums[lo] < nums[hi]) return nums[lo];
            
            if (nums[mid] > nums[hi])
                lo = mid+1;
            else
                hi = mid;
        }
        return nums[lo];
    }
};