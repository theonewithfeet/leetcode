// https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(),nums1.end());
        vector<int> result;
        
        for (auto num : nums2) 
            if (s1.erase(num) > 0)
                result.push_back(num);
        
        return result;
    }
};