// https://leetcode.com/problems/score-after-flipping-matrix/

class Solution {
    void flipRow(vector<int>& row) {
        for (int i=0; i<row.size(); i++)
            row[i] = row[i] ? 0 : 1;
    }
    void flipCol(int col,vector<vector<int>>& grid) {
        for (int row=0; row<grid.size(); row++)
            grid[row][col] = grid[row][col] ? 0 : 1;
    }
    int row2Int(vector<int>& row) {
        int sum=0;
        for (auto val : row)
            sum = (sum<<1)+val;
        return sum;
    }
public:
    int matrixScore(vector<vector<int>>& grid) {       
        for (int r=0; r<grid.size(); r++)
            if (grid[r][0] == 0)
                flipRow(grid[r]);
        
        for (int c=1; c<grid[0].size(); c++) {
            int ones=0;
            for (int r=0; r<grid.size(); r++) 
                ones += grid[r][c];     
            if (grid.size()-ones > ones)
                flipCol(c,grid);
        }
        int sum=0;
        for (int r=0; r<grid.size(); r++)
            sum += row2Int(grid[r]);
        
        return sum;
    }
};