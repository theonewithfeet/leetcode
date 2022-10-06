// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
    struct Node {
        Node *child[26] = {0};
        bool  wordend   = false;
    };
    Node root;
public:
    Trie() {}
    
    void insert(const string& word) {
        Node *node = &root;
        for (auto ch : word) {
            ch -= 'a';
            if (! node->child[ch])
                node->child[ch] = new Node;
            node = node->child[ch];
        }
        node->wordend = true;
    }
    
    bool search(const string& word) {
        Node *node = &root;
        for (auto ch : word) {
            node = node->child[ch-'a'];            
            if (! node) return false;
        }
        return node->wordend;
    }
    
    bool startsWith(const string& prefix) {
        Node *node = &root;
        for (auto ch : prefix) {
            node = node->child[ch-'a'];            
            if (! node) return false;
        }
        return true;        
    }
};
