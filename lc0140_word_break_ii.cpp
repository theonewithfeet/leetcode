// https://leetcode.com/problems/word-break-ii/ 

class Solution {
    void solve(int idx,string& str,const string& words,unordered_set<string>& dict,vector<string>& result) {
        if (idx == str.size())
            result.push_back(words);
        else {
            string word;
            for (int i=idx; i<str.size(); i++) {
                word += str[i];
                if (dict.find(word) != dict.end()) 
                    solve(i+1,str,(words.size() ? words+" "+word : word),dict,result);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<string> result;
        
        solve(0,s,"",dict,result);
        
        return result;
    }
};