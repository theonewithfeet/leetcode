// https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int used=0, total=0, index=0;
        
        for (int i=0; i<gas.size(); i++) {
            used  += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (used < 0) {
                used = 0;
                index = i+1;
            }
        }
        return total < 0 ? -1 : index;
    }
};