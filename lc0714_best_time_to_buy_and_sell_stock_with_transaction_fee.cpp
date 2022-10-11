// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sell=0, buy=-prices[0];
        
        for (int i=1; i<prices.size(); i++) {
            int prev = buy;
            buy  = max(buy, sell-prices[i]);
            sell = max(sell,prev+prices[i]-fee);
        }
        return sell;
    }
};

