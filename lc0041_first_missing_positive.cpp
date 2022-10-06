// https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
		int n=nums.size();
        vector<int> found(n+1);
        
        for (auto num : nums) 
            if (num > 0 && num <= nums.size())
                found[num]] = 1;

        for (int i=1; i<found.size(); i++)
            if (found[i] == 0) return i;
        
        return found.size();
    }
};