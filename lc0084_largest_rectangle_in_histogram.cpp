// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
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
};