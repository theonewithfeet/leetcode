// https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> sweets(ratings.size(),1);
        
        for (int i=1; i<ratings.size(); i++) 
            if (ratings[i-1] < ratings[i])
                sweets[i] = sweets[i-1]+1;
        
        int sum=sweets.back();
        for (int i=ratings.size()-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1])
                sweets[i] = max(sweets[i],sweets[i+1]+1);
            sum += sweets[i];
        }
        return sum;
    }
};