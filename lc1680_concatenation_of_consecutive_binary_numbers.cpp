// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

class Solution {
    const unsigned long prime=1e9+7;
public:
    int concatenatedBinary(int n) {
        unsigned long i=1, k=1, result=1;
        
        while (i<n) {
            int cnt = 1<<k;
            int bit = cnt<<1;;
            k++;
            while (cnt-- && i<n) {
                i++;
                result = ((result*bit)%prime + i) % prime;
            }
        }
        return result;
    }
};