int longestIncreasingSubsequence(int *arr, int n, int i, int prev) {
    if(i == n)
        return 0;
    
    int pick = 0;
    if(prev == -1 || arr[prev] < arr[i]) {
        pick = 1 + longestIncreasingSubsequence(arr, n, i + 1, i);
    } 
    
    int notpick = longestIncreasingSubsequence(arr, n, i + 1, prev);
    
    return max(pick, notpick);
}

int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
    return longestIncreasingSubsequence(arr, n, 0, -1);
}
