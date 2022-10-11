// https://leetcode.com/problems/course-schedule/

class Solution {
    bool isCycle(vector<int>& visited,vector<vector<int>>& graph,int idx) {
        if (visited[idx]) return visited[idx] == 1;
        
        visited[idx] = 1;
        
        for (auto i : graph[idx]) 
            if (isCycle(visited,graph,i))
                return true;
        
        visited[idx] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses,vector<int>());
        
        for (auto& prerequisite : prerequisites) 
            graph[prerequisite[0]].push_back(prerequisite[1]);
            
        vector<int> visited(numCourses,0);
        
        for (int i=0; i<numCourses; i++) 
            if (isCycle(visited,graph,i))
                return false;

        return true;
    }
};