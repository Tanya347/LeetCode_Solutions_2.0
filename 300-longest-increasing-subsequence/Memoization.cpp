int longestIncreasingSubsequence(int *arr, int n, int i, int prev, int** dp) {
    if(i == n)
        return 0;
    
    //as we are keeping the index as -1 initially we use prev + 1 to store values
    if(dp[i][prev + 1] != -1)
        return dp[i][prev + 1];
    
    int pick = 0;
    if(prev == -1 || arr[prev] < arr[i]) {
        pick = 1 + longestIncreasingSubsequence(arr, n, i + 1, i, dp);
    } 
    
    int notpick = longestIncreasingSubsequence(arr, n, i + 1, prev, dp);
    
    dp[i][prev + 1] = max(pick, notpick);
    return dp[i][prev + 1];
}

int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
    int **dp = new int*[n];
    for(int i = 0; i < n; i++) {
        dp[i] = new int[n + 1];
        for(int j = 0; j < n + 1; j++)
            dp[i][j] = -1;
    }
    return longestIncreasingSubsequence(arr, n, 0, -1, dp);
}
