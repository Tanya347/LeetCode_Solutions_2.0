class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPr = 0;
        int minPrice = prices[0];
        
        for(int i = 1; i < prices.size(); i++) {
            
            //keep track of min most price so far
            minPrice = min(minPrice, prices[i]);
            
            //keep track of max profit generated so far from the min most price
            maxPr = max(maxPr, prices[i] - minPrice);
        }
        
        return maxPr;
    }
};