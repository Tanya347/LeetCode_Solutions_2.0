int maxMoneyLooted(int *arr, int n, int* dp, int i)
{
	//Write your code here
    if(n <= 0)
        return 0;
    
    if(dp[i] != -1)
        return dp[i];
    
    int x = arr[0] + maxMoneyLooted(arr + 2, n - 2, dp, i + 2);
    int y = maxMoneyLooted(arr + 1, n - 1, dp, i + 1);
    
    dp[i] = max(x, y);
    return dp[i];
}

int maxMoneyLooted(int *arr, int n) {
    int *dp = new int[n + 1];
    for(int i = 0; i <= n; i++) {
        dp[i] = -1;
    }
    return maxMoneyLooted(arr, n, dp, 0);
}
