// https://leetcode.com/problems/count-array-pairs-divisible-by-k/

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<long,long> gcds;       
        long long count=0;
        
        for (auto num : nums) { 
            gcds[gcd(num,k)] += 1; 
        }
        for (auto it=gcds.cbegin(); it!=gcds.cend(); ++it)
            for (auto jt=it; jt!=gcds.cend(); ++jt)
                if ((it->first * jt->first) % k == 0)
                    if (it == jt)
                        count += (it->second * (jt->second-1)) / 2;
                    else
                        count += (it->second * jt->second);
    
        return count;
    }
};