// https://leetcode.com/problems/ugly-number/

class Solution {
    int primes[3]={2,3,5};
public:
    bool isUgly(int n) {
        if (n > 1) 
            for (auto prime : primes)
                while (n % prime == 0)
                    n /= prime;
        return n==1;
    }
};