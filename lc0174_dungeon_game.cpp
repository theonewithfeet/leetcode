// https://leetcode.com/problems/dungeon-game/

class Solution {
    int dp[1+200][1+200];
    int solve(int i,int j,int m,int n,vector<vector<int>>& dungeon) {
        if (i==m || j==n) return INT_MAX;
        
        if (i==m-1 && j==n-1) return (dungeon[i][j] <= 0) ? abs(dungeon[i][j]) + 1 : 1;
        
        if (dp[i][j] == -1) {
            int rt = solve(i,j+1,m,n,dungeon);
            int dn = solve(i+1,j,m,n,dungeon);
            
            int health = min(rt,dn) - dungeon[i][j];
            dp[i][j] = (health <= 0) ? 1 : health;
        }
        return dp[i][j];
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,dungeon.size(),dungeon[0].size(),dungeon);
    }
};