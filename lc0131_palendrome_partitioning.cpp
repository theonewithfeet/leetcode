// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
    bool isPalendrome(const string& str,int i,int n) {
        for (int j=n-1; i<j; i++, j--)
            if (str[i] != str[j])
                return false;
        return true;
    }
        
    void solve(vector<vector<string>>& result,vector<string>& path,const string& suffix) {
        if (suffix.empty()) 
            result.push_back(path);
        else {
            for (int i=1; i<=suffix.size(); i++) {
                if (isPalendrome(suffix,0,i)) {
                    path.push_back(suffix.substr(0,i));
                    solve(result,path,suffix.substr(i));
                    path.pop_back();
                }
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        
        solve(result,path,s);
        
        return result;
    }
};