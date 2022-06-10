int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    if(n <= 0)
        return 0;
    
    int x = arr[0] + maxMoneyLooted(arr + 2, n - 2);
    int y = maxMoneyLooted(arr + 1, n - 1);
    
    return max(x, y);
}
