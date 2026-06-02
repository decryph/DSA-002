class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = prices[0], profit = 0;

        for(int i =0; i<prices.size();i++){
            int cost = prices[i]-minP;
            profit = max(cost,profit);
            minP = min(minP, prices[i]);
        }
        return profit;
    }
};