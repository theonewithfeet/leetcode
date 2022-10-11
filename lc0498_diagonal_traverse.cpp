// https://leetcode.com/problems/diagonal-traverse/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size(), row=0, col=0, up=1;;
        vector<int> result(m*n);
        
        for (int i=0; i<m*n; i++) {
            result[i] = mat[row][col];
            if (up) {
                if (col == n-1)
                    row++, up=0;
                else if (row == 0)
                    col++, up=0;
                else
                    row--, col++;
            } 
            else {
                if (row == m-1)
                    col++, up=1;
                else if (col == 0)
                    row++, up=1;
                else
                    row++, col--;
            }
        }
        return result;
    }
};