// https://leetcode.com/problems/vowel-spellchecker/

class Solution {
    string stripVowels(const string& s) {
        string out;
        for (auto c : s) {
            switch (c) {
                case 'a': case 'e': case 'i': case 'o': case 'u':
                case 'A': case 'E': case 'I': case 'O': case 'U':
                    c = '.';
                default:
                    break;
            };
            out += c;
        }
        return out;
    }
    string toLower(const string& s) {
        string out;
        for (auto c : s)
            out += tolower(c);
        return out;
    }
    
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string,string> capitals;
        unordered_map<string,string> vowels;
        unordered_set<string> words;     
        
        for (auto word : wordlist) {
            words.insert(word);            
            string low = toLower(word);
            if (capitals.count(low) == 0) 
                capitals[low] = word;
            low = stripVowels(low);
            if (vowels.count(low) == 0)
                vowels[low] = word;
        }
        vector<string> result(queries.size());
        
        for (int i=0; i<queries.size(); i++) {
            if (words.count(queries[i])) {
                result[i] = queries[i];
                continue;
            }
            string low = toLower(queries[i]);
            auto it = capitals.find(low);
            if (it != capitals.end()) {
                result[i] = it->second;
                continue;
            }
            low = stripVowels(low);
            if (vowels.count(low))
                result[i] = vowels[low];
        }
        
        return result;
    }
};