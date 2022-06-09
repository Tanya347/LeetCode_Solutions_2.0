//TOP LEFT TO BOTTOM RIGHT

int minCostPath(int **input, int m, int n, int i, int j)
{
	//Write your code here
    if(i == m || j == n)
        return INT_MAX;
    
    if(i == m - 1 && j == n - 1)
        return input[i][j];
    
    
    int x = minCostPath(input, m, n, i + 1, j);
    int y = minCostPath(input, m, n, i, j + 1);
    int z = minCostPath(input, m, n, i + 1, j + 1);
    
    return input[i][j] + min(x, min(y, z));
}

int minCostPath(int **input, int m, int n)
{
	//Write your code here
    minCostPath(input, m, n, 0, 0);
}

//BOTTOM RIGHT TO TOP LEFT

int minCostPath(int **input, int m, int n) {
    if(m <= 0 || n <= 0) {
        return INT_MAX;
    }
    
    if(m == 1 && n == 1) {
        return input[m - 1][n - 1];
    }
    
    int x = minCostPath(input, m - 1, n);
    int y = minCostPath(input, m, n - 1);
    int z = minCostPath(input, m - 1, n - 1);
    
    return input[m - 1][n - 1] + min(x, min(y, z));
}
