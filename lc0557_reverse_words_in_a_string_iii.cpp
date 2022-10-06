// https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string result, word;
        while (ss >> word) {
            if (! result.empty())
                result += ' ';
            for (int i=word.size()-1; i>=0; i--)
                result += word[i];
        }
        return result;
    }
};