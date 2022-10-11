// https://leetcode.com/problems/max-points-on-a-line/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 2) return points.size();
        
        int result=0, n=points.size(); 
        for (int i=0; i<n; i++) {
            int x1=points[i][0], y1=points[i][1];
            for (int j=i+1; j<n; j++) {
                int x2=points[j][0], y2=points[j][1], total=2;                
                for (int k=0; k<n; k++) {
                    if (k==i || k==j) continue;
                    int x=points[k][0], y=points[k][1];
                    
                    if ((y2-y1)*(x-x1) == (x2-x1)*(y-y1))
                        total += 1;
                }
                result = max(result,total);
            }
        }
        return result;
    }
};
    
