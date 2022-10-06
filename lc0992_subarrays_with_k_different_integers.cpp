// https://leetcode.com/problems/subarrays-with-k-different-integers/

class Solution {
    int subarrayWithAtMostK(vector<int>& nums,int k) {
        vector<int> counts(nums.size()+1);
        int total=0, count=0;
        for (int lo=0, hi=0; hi<nums.size(); hi++) {
            count += (counts[nums[hi]] += 1) == 1 ? 1 : 0;;
            while (count > k) {
                if ((counts[nums[lo]] -= 1) == 0)
                    count -= 1;
                lo += 1;
            }
            total += hi-lo+1;
        }
        return total;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayWithAtMostK(nums,k) - subarrayWithAtMostK(nums,k-1); 
    }
};