// https://leetcode.com/problems/arithmetic-subarrays/

class Solution {
    bool isArithmetic(vector<int>& v) {
        if (v.size() < 2) 
            return false;
        sort(v.begin(),v.end());
        int diff=v[1]-v[0];
        for (int i=1; i<v.size(); i++)
            if (v[i]-v[i-1] != diff)
                return false;
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result;
        
        for (int i=0; i<r.size(); i++) {
            vector<int> temp(nums.begin()+l[i],nums.begin()+r[i]+1);           
            result.push_back(isArithmetic(temp));
        }
        return result;
    }
};