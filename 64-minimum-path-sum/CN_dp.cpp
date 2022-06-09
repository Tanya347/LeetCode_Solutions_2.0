int minCostPath(int **input, int m, int n)
{
	//Write your code here
    
    int **dp = new int*[m];
    for(int i = 0; i < m; i++) {
        dp[i] = new int[n];
    }
    
    dp[m - 1][n - 1] = input[m - 1][n - 1];
    
    for(int i = m - 2; i >= 0; i--) {
        dp[i][n - 1] = input[i][n - 1] + dp[i + 1][n - 1];
    }
    
    for(int i = n - 2; i >= 0; i--) {
        dp[m - 1][i] = input[m - 1][i] + dp[m - 1][i + 1];
    }
    
    for(int i = m - 2; i >= 0; i--) {
        
        for(int j = n - 2; j >= 0; j--) {
            
            dp[i][j] = input[i][j] + min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1]));
        }
    }
    
    return dp[0][0];
}
