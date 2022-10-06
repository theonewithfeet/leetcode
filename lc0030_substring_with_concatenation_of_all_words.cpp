// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len=words[0].length(), n=words.size();
        
        unordered_map<string,int> w;
        
        for (int i=0; i<n; i++) 
            w[words[i]] += 1;
        
        vector<int> result;
        
        auto count = w;
                
        for (int i=0; i<s.length(); i++) {
            auto it = count.find(s.substr(i,len));
            
            if (it != count.end()) {
                int found = 1;

                if (found == n) {
                    result.push_back(i);
                    continue;
                }
                it->second -= 1;
                
                for (int j=i+(n-1)*len; j>i && j<s.length(); j-=len) {
                    auto it = count.find(s.substr(j,len));
                    
                    if (it == count.end() || it->second == 0) {
                        count = w;
                        break;
                    }
                    it->second -= 1;
                    found += 1;
                    
                    if (found == n) {
                        result.push_back(i);
                        count = w;
                        break;
                    }
                }
            }
        }
        return result;
    }

};