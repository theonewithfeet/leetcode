// https://leetcode.com/problems/factorial-trailing-zeroes/

class Solution {
public:
    int trailingZeroes(int n) {
        int zeros=0;
        
        while (n) 
            zeros += n /= 5;

        return zeros;
    }
};