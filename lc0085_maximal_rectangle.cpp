// https://leetcode.com/problems/maximal-rectangle/

class Solution {
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(), area=0;
        stack<int> st;
        
        for (int i=0; i <= n; i++) {
            int curr = i==n ? 0 : heights[i];
            
            while (st.size() && curr < heights[st.top()]){
                int y = st.top(); st.pop(); 
                int x = st.empty() ? i : i - st.top() - 1; 
                area  = max(area, heights[y] * x); 
            }
            st.push(i);
        }
        return area;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size(), area=0;
        
        vector<int> heights(n,0);
        
        for (int r=0; r<m; r++) {
            for (int c=0; c<n; c++)
                heights[c] = matrix[r][c]=='1' ? heights[c] + 1 : 0;
            
            area = max(area,largestRectangleArea(heights));
        }
        return area;
    }
};