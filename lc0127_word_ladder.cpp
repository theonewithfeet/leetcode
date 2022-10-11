// https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        if (dict.count(endWord) == 0) return 0;
        
        queue<string> todo;
        int ladder=0;
        
        todo.push(beginWord);
        dict.erase(beginWord);
        
        while (todo.size()) {
            ladder += 1;
            int size = todo.size();
            while (size--) {
                string word = todo.front(); todo.pop();
                if (word == endWord) return ladder;

                for (int i=0; i<word.size(); i++) {
                    auto ch = word[i];
                    for (char c='a'; c<='z'; c++) {
                        word[i] = c;
                        if (dict.count(word)) {
                            todo.push(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = ch;
                }
            }
        }
        return 0;
    }
};