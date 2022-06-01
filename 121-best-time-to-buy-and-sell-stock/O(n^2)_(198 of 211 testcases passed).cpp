class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPr = INT_MIN;
        
        for(int i = 0; i < prices.size(); i++) {
            int diff = 0;
            for(int j = i + 1; j < prices.size(); j++) {
                if(prices[j] > prices[i])
                    diff = prices[j] - prices[i];
                maxPr = max(diff, maxPr);
            }
        }
        
        if(maxPr == INT_MIN) 
            return 0;
        else
            return maxPr;
    }
};
