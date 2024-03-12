class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy =0;
        int sell =1;
        int profit = 0;
        int n=prices.size();

        while(sell<n)
        {
            if(prices[sell] > prices[buy])
            {
                profit = max(profit , prices[sell] - prices[buy]);
                sell++;
            }
            else
            { 
                buy = sell;
                sell++;
            }
        }
        return profit;
        
    }
};