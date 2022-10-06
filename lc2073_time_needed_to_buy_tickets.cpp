// https://leetcode.com/problems/time-needed-to-buy-tickets/

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int seconds=0;     
        while (tickets.size()) {
            for (int i=0; i<tickets.size(); i++) {
                auto& ticket = tickets[i];
                if (ticket) {
                    ticket -= 1;
                    seconds+= 1;
                    if (ticket == 0 && i == k) return seconds;
                }
            }
        }
        return seconds;
    }
};