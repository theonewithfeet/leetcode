// https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degrees(numCourses,0);
        vector<vector<int>> graph(numCourses,vector<int>());
        
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            degrees[pre[0]] += 1;
        }
        queue<int> qu;
        
        for (int i=0; i<numCourses; i++)
            if (degrees[i] == 0)
                qu.push(i);
        
        vector<int> result;
        
        while (! qu.empty()) {
            int course = qu.front(); qu.pop();
            result.push_back(course);
            for (auto next : graph[course]) 
                if (--degrees[next] == 0)
                    qu.push(next);
        } 
        
        if (result.size() != numCourses)
            return {};
        
        return result;
    }
};