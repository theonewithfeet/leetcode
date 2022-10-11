// https://leetcode.com/problems/repeated-dna-sequences/

class Solution {
    int lookup[128] = {0};
public:
    Solution() {
        lookup['C'] = 1;
        lookup['G'] = 2;
        lookup['T'] = 3;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<bool>   seen(0xFFFFF+1);
        vector<bool>   dups(0xFFFFF+1);
        vector<string> result;
        
        for (int i=0, hash=0; i<s.size(); i++, hash<<=2) {
            hash |= lookup[s[i]];
            hash &= 0xFFFFF;
            if (i>=9 && dups[hash] == false) {
                if (seen[hash]) {
                    result.push_back(s.substr(i-9,10));
                    dups[hash] = true;
                }
                seen[hash] = true;
            }            
        }
        return result;
    }
};