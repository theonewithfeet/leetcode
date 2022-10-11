// https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution {
    static bool cmp(const vector<int>& a,const vector<int>& b) {
        if (a[1] == b[1]) return a[0] < b[0];       
        return a[1] < b[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        
        int count=1, last=pairs[0][1];
        for (auto& p : pairs)
            if (last < p[0]) {
                count += 1;
                last = p[1];
            }        
        return count;
    }
};