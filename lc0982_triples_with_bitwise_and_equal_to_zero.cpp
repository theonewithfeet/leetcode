// https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (auto num1 : nums)
            for (auto num2 : nums)
                mp[num1 & num2] += 1;
        int count=0;
        for (auto [a, b] : mp)
            for (auto num : nums)
                if ((a & num) == 0)
                    count += b;
        return count;
    }
};