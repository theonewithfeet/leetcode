// https://leetcode.com/problems/query-kth-smallest-trimmed-number/

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> result;
        int len = nums[0].size();
        for (auto& query : queries) {
            vector<pair<string,int>> trim;
            int k=query[0],x=len-query[1];
            for (int i=0; i<nums.size(); i++)
                trim.emplace_back(nums[i].substr(x),i);
            sort(trim.begin(),trim.end());
            result.push_back(trim[k-1].second);
        }
        return result;
    }
};