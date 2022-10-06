// https://leetcode.com/problems/count-lattice-points-inside-a-circle/

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int count=0, maxx=0, maxy=0;
        for (auto& circle : circles) {
            maxx = max(maxx,circle[0]+circle[2]);
            maxy = max(maxy,circle[1]+circle[2]);
        }
        for (int x=0; x<=maxx; x++)
            for (int y=0; y<=maxy; y++)
                for (auto& circle : circles) 
                    if ((circle[0]-x)*(circle[0]-x) + (circle[1]-y)*(circle[1]-y) <= (circle[2]*circle[2])) {
                        count += 1;
                        break;
                    }
        return count;
    }
};