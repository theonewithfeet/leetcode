// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triples;
                
        sort(nums.begin(),nums.end());
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > 0) break;
            
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int j=i+1, k=nums.size()-1;
            
            while (j<k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum < 0) 
                    j += 1;
                else if (sum > 0)
                    k -= 1;
                else {
                    triples.push_back({nums[i],nums[j],nums[k]});
                    do { j++; } while (j<k && nums[j-1] == nums[j]);
                    do { k--; } while (j<k && nums[k+1] == nums[k]);
                }
            }
        }
        return triples;                             
    }
};