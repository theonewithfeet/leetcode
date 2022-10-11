// https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/

class Solution {
    int str2freq(const string& s) {
        int freq[26]={0}, fmin=INT_MAX;
        for (auto ch: s) {
            ch -= 'a';
            freq[ch] += 1;
            fmin = min(fmin,int(ch));
        }
        return freq[fmin];
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int freq[10+2] = {0};
        for (auto word : words) { freq[str2freq(word)] += 1; }
        
        for (int i=10-1; i>=0; i--)
            freq[i] += freq[i+1];
        
        vector<int> result(queries.size());
        
        for(int i=0; i<queries.size(); i++) {
            int f = str2freq(queries[i]);
            result[i] = freq[f+1];
        }
        return result;
    }
};