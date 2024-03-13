class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int end = 1;
        int max =0;
        while(end<prices.size())
        {
            if(prices[end-1] < prices[end])
            {
                max += prices[end] - prices[end-1];
            }
            end++;
        }

        return max;
        
    }
};