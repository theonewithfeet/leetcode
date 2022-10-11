// https://leetcode.com/problems/find-duplicate-file-in-system/

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> mp;
        
        for (auto s : paths) {
            istringstream ss(s);
            string path, file;
            getline(ss,path,' ');
            while (getline(ss,file,'(')) {
                string data;
                getline(ss,data,' ');
                mp[data].emplace_back(path+'/'+file);
            }
        }
        vector<vector<string>> result;
        
        for (auto& [a, b] : mp) 
            if (b.size() > 1)
                result.emplace_back(b);
        
        return result;
    }
};