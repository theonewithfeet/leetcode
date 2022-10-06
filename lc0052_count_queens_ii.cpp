// https://leetcode.com/problems/n-queens-ii/

class Solution {
    bool canAddQueen(const vector<string>& b,int r,int c) {
        for (int i=r-1, j=c-1, k=c+1; i>=0; i--, j--, k++)
            if ((j >= 0 && b[i][j] == 'Q') || (k < b.size() && b[i][k] == 'Q') || b[i][c] == 'Q')
                return false;
        return true;
    }
    int countQueens(vector<string>& b,int r) {
        int count = 0;
        for (int c=0; c<b.size(); c++) {
            if (canAddQueen(b,r,c)) {
                b[r][c] = 'Q';
                if (r == b.size()-1) 
                    count += 1;
                else 
                    count += countQueens(b,r+1);
                b[r][c] = '.';
            }
        }
        return count;
    }

public:
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
                             
        return countQueens(board,0);       
    }
};
