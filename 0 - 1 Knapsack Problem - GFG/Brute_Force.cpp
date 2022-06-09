int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
    if(n == 0 || maxWeight <= 0)
        return 0;
        
    if(maxWeight < weights[0]) {
        return knapsack(weights + 1, values + 1, n - 1, maxWeight);
    }
        
    int x = values[0] + knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]);
    int y = knapsack(weights + 1, values + 1, n - 1, maxWeight);
    
    return max(x, y);
}
