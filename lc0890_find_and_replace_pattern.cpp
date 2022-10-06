// https://leetcode.com/problems/find-and-replace-pattern/

class Solution {
    bool check(const string& word,const string& pattern) {
        char mapping[128]={0}, mapped[128]={0};
        for (int i=0; i<pattern.size(); i++) {
            auto ch = pattern[i];
            if (mapping[ch] == 0) {
                if (mapped[word[i]] != 0) 
                    return false;
                mapped[word[i]] = 1;
                mapping[ch] = word[i];
            }
            else if (mapping[ch] != word[i])
                return false;
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        
        for (auto word : words) 
            if (check(word,pattern))
                result.push_back(word);
        
        return result;
    }
};