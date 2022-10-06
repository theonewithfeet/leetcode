// https://leetcode.com/problems/number-of-visible-people-in-a-queue/

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int> result(n), stk;
        for (int i=0; i < n; i++) {
            while (!stk.empty() && heights[stk.back()] <= heights[i])
                result[stk.back()]++, stk.pop_back();
            if (!stk.empty())
                result[stk.back()]++;
            stk.push_back(i);
        }
        return result; 
    }
};