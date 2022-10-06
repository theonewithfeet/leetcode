// https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/

class Solution {
    struct bigger {
        inline bool operator()(const string& a,const string& b) {
            return a.size() > b.size() || a.size()==b.size() && a > b;      
        }
    };
    bigger bg;
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,bigger> pq;
        
        for (int i=0; i<k; i++)
            pq.push(nums[i]);
        
        for (int i=k; i<nums.size(); i++)
            if (bg(nums[i],pq.top())) {
                pq.push(nums[i]);
                pq.pop();
            }
        
        return pq.top();
    }
};