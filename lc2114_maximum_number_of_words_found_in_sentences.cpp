// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxwords=0;
        
        for (auto& sentence : sentences) {
            int count=0;
            for (auto ch : sentence)
                if (ch == ' ') count++;
            maxwords = max(maxwords,count);
        }
        return maxwords+1;
    }
};