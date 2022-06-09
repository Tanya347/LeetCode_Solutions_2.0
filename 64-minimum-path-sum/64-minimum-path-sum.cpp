class Solution {
public:
    
    int minPathSum(vector<vector<int>>& input) {
        int m = input.size();
        int n = input[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
    
        if(m == 1 && n == 1)
            return input[m - 1][n - 1];
        
        for(int i = m - 1; i >= 0; i--) {
            
            for(int j = n - 1; j >= 0; j--) {
                
                if(i == m - 1 && j == n - 1)
                    dp[i][j] = input[i][j];
                
                else if(i != m - 1 && j == n - 1)
                    dp[i][j] = input[i][j] + dp[i + 1][j];
                
                else if(i == m - 1 && j != n - 1)
                    dp[i][j] = input[i][j] + dp[i][j + 1];
                
                else 
                    dp[i][j] = input[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
            }
        }
                               
        return dp[0][0];
    }
};