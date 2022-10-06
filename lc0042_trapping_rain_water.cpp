// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int water=0, *lo=height.data(), *hi=height.data()+height.size()-1, lo_max=0, hi_max=0;
        
        while (lo < hi) {
            if (*lo < *hi) {
                if (*lo > lo_max)
                    lo_max = *lo;
                else
                    water += lo_max - *lo;
                lo++;
            }
            else {
                if (*hi > hi_max)
                    hi_max = *hi;
                else
                    water += hi_max - *hi;
                hi--;
            }
        }
        return water;
    }
};