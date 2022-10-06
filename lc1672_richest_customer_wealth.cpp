// https://leetcode.com/problems/richest-customer-wealth/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int wealth=0;
        for (auto& account:accounts) {
            int sum=0;
            for (auto value:account) 
                sum += value;
            wealth = max(wealth,sum);
        }
        return wealth;
    }
};