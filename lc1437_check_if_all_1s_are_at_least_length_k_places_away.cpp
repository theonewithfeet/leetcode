// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count=k;
        for (auto num : nums)
            if (num) {
                if (count < k) return false;
                count = 0;
            }
            else
                count += 1;

        return true;
    }
};