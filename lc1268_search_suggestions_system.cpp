// https://leetcode.com/problems/search-suggestions-system/

class Solution {
    bool check(int len,const string& a,const string& b) {
        for (int i=0; i<len; i++)
            if (a[i] != b[i])
                return false;
        return true;
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string search) {
        vector<vector<string>> result;
        
        sort(products.begin(),products.end());
        
        string prefix;
        int index, start=0;
        for (int i=0; i<search.size(); i++) {
            prefix += search[i];
            
            index = lower_bound(products.begin()+start,products.end(),prefix) - products.begin();
            
            result.push_back({});
            
            for (int j=index; j<products.size() && j<index+3 && check(i+1,prefix,products[j]); j++)
                result.back().push_back(products[j]);
            
            start = index;
        }
        return result;
    }
};