// https://leetcode.com/problems/making-file-names-unique/

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string,int> mp;
        vector<string> actual;
        
        for (auto name : names) {
            if (mp.count(name) == 0) {
                actual.push_back(name);
                mp[name] = 0;
            }
            else {
                int x = mp[name]+1;
                string uname = name+'('+to_string(x)+')';
                
                while (mp.count(uname)) 
                    uname = name+'('+to_string(++x)+')';
                
                actual.push_back(uname);
                mp[uname];
                mp[name] = x;
            }
        }
        return actual;   
    }
};