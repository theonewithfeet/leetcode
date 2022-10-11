// https://leetcode.com/problems/surrounded-regions/

class Solution {
    void markFrom(int r,int c,vector<vector<char>>& board) {
        if (r>=0 && r<board.size() && c>=0 && c<board[0].size() && board[r][c] == 'O') {
            board[r][c] = 'F';
            markFrom(r+1,c,board);
            markFrom(r-1,c,board);
            markFrom(r,c+1,board);
            markFrom(r,c-1,board);
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        
        for (int i=0; i<m; i++) {
            if (board[i][0] == 'O')   markFrom(i,0,board);
            if (board[i][n-1] == 'O') markFrom(i,n-1,board);
        }
        for (int i=1; i<n; i++) {
            if (board[0][i] == 'O')   markFrom(0,i,board);
            if (board[m-1][i] == 'O') markFrom(m-1,i,board);
        }
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (board[i][j] == 'F')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
    }
};