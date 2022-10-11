// https://leetcode.com/problems/find-original-array-from-doubled-array/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2) return {};
        
        map<int,int> nums;
        for (auto num:changed) { nums[num] += 1; }

        vector<int> result;
        while (result.size() < changed.size() / 2) {
            auto lo = nums.begin();
            auto hi = nums.find(lo->first * 2);
            
            if (hi == nums.end() || hi == lo && lo->second % 2) return {};
            
            result.push_back(lo->first);
            
            lo->second -= 1;
            hi->second -= 1;
            
            if (lo != hi && lo->second == 0) nums.erase(lo);
            if (hi->second == 0) nums.erase(hi);
        }
        return result;
    }
};