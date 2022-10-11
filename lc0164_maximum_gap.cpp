// https://leetcode.com/problems/maximum-gap/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        
        int lo=INT_MAX, hi=INT_MIN, n=nums.size();
        for (auto num : nums) {
            lo = min(lo,num);
            hi = max(hi,num);
        }
        if (hi == lo) return 0;
        
        int gap = int(ceil(double(hi-lo)/(n-1)));
        vector<pair<int,int>> buckets(n,{INT_MAX,INT_MIN});
        
        for (auto num : nums) {
            auto& bucket  = buckets[(num-lo)/gap];
            bucket.first  = min(bucket.first,num);
            bucket.second = max(bucket.second,num);
        }
        int result=gap, prev=lo;
        for (auto& bucket : buckets) {
            if (bucket.first == INT_MAX) continue;
            result = max(result,bucket.first-prev);
            prev   = bucket.second;
        }
        return result;
    }
};