//TOP LEFT TO BOTTOM RIGHT

int minCostPath(int **input, int m, int n, int i, int j, int** output)
{
	//Write your code here
    if(i == m || j == n)
        return INT_MAX;
    
    if(i == m - 1 && j == n - 1)
        return input[i][j];
    
    if(output[i][j] != -1) 
        return output[i][j];
    
    int x = minCostPath(input, m, n, i + 1, j, output);
    int y = minCostPath(input, m, n, i, j + 1, output);
    int z = minCostPath(input, m, n, i + 1, j + 1, output);
    
    output[i][j] = input[i][j] + min(x, min(y, z));
    
    return output[i][j];
}

int minCostPath(int **input, int m, int n)
{
	//Write your code here
    
    int **output = new int*[m + 1];
    for(int i = 0; i <= m; i++) {
        output[i] = new int[n + 1];
        for(int j = 0; j <= n; j++) {
            output[i][j] = -1;
        }
    }
    
    minCostPath(input, m, n, 0, 0, output);
}

//BOTTOM RIGHT TO TOP LEFT

int minCostPath(int **input, int m, int n, int** output) {
    if(m <= 0 || n <= 0) {
        return INT_MAX;
    }
    
    if(m == 1 && n == 1) {
        return input[m - 1][n - 1];
    }
    
    if(output[m - 1][n - 1] != -1) 
        return output[m - 1][n - 1];
    
    int x = minCostPath(input, m - 1, n, output);
    int y = minCostPath(input, m, n - 1, output);
    int z = minCostPath(input, m - 1, n - 1, output);
    
    output[m - 1][n - 1] = input[m - 1][n - 1] + min(x, min(y, z));
    
    return output[m - 1][n - 1];
}

int minCostPath(int **input, int m, int n) {
    
    int **output = new int*[m + 1];
    for(int i = 0; i <= m; i++) {
        output[i] = new int[n + 1];
        for(int j = 0; j <= n; j++) {
            output[i][j] = -1;
        }
    }
    
    minCostPath(input, m, n, output);
}
