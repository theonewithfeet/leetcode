// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {        
        int area=0, i=0, j=height.size()-1, *p = height.data();
        
        while (i<j) {
            int h = min(p[i], p[j]);
            
            area = max(area, h * (j-i));
            
            while (i < j && p[i] <= h) i++;
            while (i < j && p[j] <= h) j--;
        }
        return area; 
    }
};
