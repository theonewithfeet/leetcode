// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {        
        unordered_map<int,int> idx;
        vector<int> result;
        for (int i=0; i<nums.size(); i++) {
            auto it = idx.find(target - nums[i]);
            if (it != idx.end()) {
                result.push_back(it->second);
                result.push_back(i);
                break;
            }
            idx[nums[i]] = i;
        }
        return result;
    }
};
