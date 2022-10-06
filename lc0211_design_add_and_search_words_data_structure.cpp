// https://leetcode.com/problems/design-add-and-search-words-data-structure/

class WordDictionary {
    struct Node { Node* next[26]={0}; bool isword=false; };
    Node root;
    
    bool find(const char* word,Node* node) {
        for (int i=0; word[i] && node; i++) {
            if (word[i] == '.') {
                for (int j=0; j<26; j++)
                    if (node->next[j] && find(word+i+1,node->next[j]))
                        return true;
                return false;
            }
            node = node->next[word[i]-'a'];
        }
        return node && node->isword;
    }
public:
    WordDictionary() {}
    
    void addWord(const string& word) {
        Node* node=&root;
        for (auto ch : word) {
            ch -= 'a';
            if (! node->next[ch])
                node->next[ch] = new Node;
            node = node->next[ch];
        }
        node->isword = true;
    }
    
    bool search(const string& word) {
        return find(word.c_str(),&root);
    }
};