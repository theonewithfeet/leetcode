// https://leetcode.com/problems/text-justification/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        
        int i=0, j=0;
        
        while (i<words.size()) {
            int len=0;
            do {
                len += words[j++].size()+(i==j ? 0:1);
            } 
            while (j < words.size() && len+words[j].size() <= maxWidth);

            int spaces=(maxWidth-len)+(j-i);
            
            if (j < words.size()) 
                for (int k=i; spaces>0; k++) {
                    if (k >= j-1) k = i;
                    words[k] += ' ';
                    spaces--;
                }
            else {
                for (int k=i; k<j-1; k++) {
                    words[k] += ' ';
                    spaces--;
                }
                while (spaces--)
                    words[j-1] += ' ';
            }
            string s;
            while (i<j)
                s += words[i++];
            
            result.push_back(s);
        }
        return result;
    }
};