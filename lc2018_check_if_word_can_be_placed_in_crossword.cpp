// https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/

class Solution {
    int m, n, len;
    
    bool check(vector<vector<char>>& board,int r,int c,const string& word,bool down) {
        if (down) { if (r+len > m || r+len < m && board[r+len][c] != '#') return false; }
        else      { if (c+len > n || c+len < n && board[r][c+len] != '#') return false; }
        
        bool fwd=true, bak=true;
        int  rinc=down?1:0, cinc=down?0:1;
        
        for (int i=0, j=len-1; i<len && (fwd || bak); i++, j--) {
            auto ch = board[r][c];
            if (ch != ' ') {
                if (fwd && word[i] != ch) fwd = false;
                if (bak && word[j] != ch) bak = false;
            }
            r += rinc;
            c += cinc;
        }
        return fwd || bak;
    }
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        m=board.size(), n=board[0].size(), len=word.size();
        
        string before(max(m,n),'#'), above(max(m,n),'#');
        
        for (int r=0; r<m; r++) {
            for (int c=0; c<n; c++) {
                auto ch = board[r][c];
                if (ch != '#') 
                    if (before[r] == '#' && check(board,r,c,word,false) || above[c] == '#' && check(board,r,c,word,true))
                        return true;
                before[r] = above[c] = ch;
            }
        }
        return false;
    }
};