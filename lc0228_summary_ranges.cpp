// https://leetcode.com/problems/summary-ranges/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        
        int first=nums[0], second=nums[0], n=nums.size();
        vector<string> result;
        
        for (int i=1; i<=n; i++) {
            if (i==n || second < nums[i]-1) {
                result.push_back(to_string(first));
                if (first != second)
                    result.back() += "->"+to_string(second);
                
                if (i<n) first = second = nums[i];
            }
            else
                second = nums[i];
        }
        return result;
        
    }
};