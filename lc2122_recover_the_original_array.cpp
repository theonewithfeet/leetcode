// https://leetcode.com/problems/recover-the-original-array/

class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        multiset<int> ms(nums.begin(),nums.end());
        
        int start = *(ms.begin());
        
        for (auto it=next(ms.begin()); it != ms.end(); ++it) {
            int k2 = *it-start;            
            if (k2==0 || k2&1) continue;
            
            multiset<int> copy(ms);
            vector<int> result;
            
            while (! copy.empty()) {
                auto hit = copy.find(k2 + *(copy.begin()));
                if (hit == copy.end()) break;
                result.push_back(*hit - k2/2);
                copy.erase(copy.begin());
                copy.erase(hit);
            }
            if (copy.empty()) return result;
        }
        return {};
    }
};