// https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/ 

class Solution {
    static bool compare(const vector<int>& a,const vector<int>& b) {
        return a[1] > b[1] || a[1] == b[1] && a[0] > b[0];
    }
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> tmp;
        
        for (auto r : restaurants) 
            if ((veganFriendly == 0 || veganFriendly && r[2]) && r[3] <= maxPrice && r[4] <= maxDistance)
                tmp.push_back(r);
        
        sort(tmp.begin(),tmp.end(),compare);
        
        vector<int> result;
        
        for (auto r : tmp) { result.push_back(r[0]); }
        
        return result;
    }
};