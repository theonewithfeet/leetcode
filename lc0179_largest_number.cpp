// https://leetcode.com/problems/largest-number/

class Solution {
    static bool greater(const string& s1,const string& s2) { return s1+s2>s2+s1; }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs(nums.size());
        
        for (int i=0; i<nums.size(); i++)  
            strs[i] = to_string(nums[i]); 
        
        sort(strs.begin(),strs.end(),greater);
        
        string result;
        for (int i=0; i<strs.size(); i++)
            result += strs[i];
        
        int i=0;
        while (result[i] == '0') 
            i++;
        
        if (i > 0)
            result = i==result.size() ? "0" : result.substr(i);
        
        return result;
    }
};