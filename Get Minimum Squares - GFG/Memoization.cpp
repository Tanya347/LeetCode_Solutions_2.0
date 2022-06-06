int minCount(int n, int* mem) {
    if(n <= 3) {
        return n;
    } else if(sqrt(n) - floor(sqrt(n)) == 0) {
        return 1;
    }
    
    if(mem[n] != -1)
        return mem[n];
    
    int min = INT_MAX;
    for(int i = 1; i <= sqrt(n); i++) {
        int ans = minCount(n - i*i, mem);
        if(ans < min)
            min = ans;
    }
    
    mem[n] = min + 1;
    return mem[n];
}

int minCount(int n)
{
	//Write your code here
    int *mem = new int[n + 1];
    
    for(int i = 0; i <= n; i++) {
        mem[i] = -1;
    }
    
    return minCount(n, mem);
}
