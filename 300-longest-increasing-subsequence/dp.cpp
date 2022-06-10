#include<vector>

int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
    
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));
                               
    for(int i = n - 1; i >= 0; i--){
        for(int j= i - 1; j >= -1; j--){
            int pick = 0;
            if(j == -1 || arr[i] > arr[j]){
                pick = 1 + dp[i + 1][i + 1];
            }
            int notpick = dp[i + 1][j + 1];
                
            dp[i][j + 1] = max(pick, notpick);
        }
    }
                               
    return dp[0][0];
}
