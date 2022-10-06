// https://leetcode.com/problems/number-of-digit-one/

class Solution {
public:
    int countDigitOne(int n) {
        int count=0;
        for (int64_t pos=1, div=0, rem=0; pos<=n; pos*=10) {
            div = pos*10;
            rem = n % div - pos + 1;
            count += (n / div) * pos;
            count += min(max(rem, int64_t(0)), pos);
        }
        return count;
    }
};