// https://leetcode.com/problems/count-primes/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n,true);
        int count=0;
        for (long i=2; i<n; i++)
            if (primes[i]) {
                count += 1;
                for (long j=i*i; j<n; j+=i)
                    primes[j] = false;
            }
        return count;
    }
};