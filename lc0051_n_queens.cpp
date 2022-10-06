// https://leetcode.com/problems/n-queens/

class Solution {
    bool canAddQueen(const vector<string>& b,int r,int c) {
        for (int i=r-1, j=c-1, k=c+1; i>=0; i--, j--, k++)
            if ((j >= 0 && b[i][j] == 'Q') || (k < b.size() && b[i][k] == 'Q') || b[i][c] == 'Q')
                return false;
        return true;
    }
    void addQueens(vector<string>& b,int r,vector<vector<string>>& results) {
        for (int c=0; c<b.size(); c++) {
            if (canAddQueen(b,r,c)) {
                b[r][c] = 'Q';
                if (r == b.size()-1) 
                    results.push_back(b);
                else 
                    addQueens(b,r+1,results);
                b[r][c] = '.';
            }
        }               
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> board(n,string(n,'.'));
                             
        addQueens(board,0,results);
                             
        return results;   
    }
};