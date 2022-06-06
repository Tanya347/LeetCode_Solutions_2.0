int minCount(int n)
{
	//Write your code here
    if(n <= 3) {
        return n;
    } else if(sqrt(n) - floor(sqrt(n)) == 0) {
        return 1;
    }
    
    int min = INT_MAX;
    for(int i = 1; i <= sqrt(n); i++) {
        int ans = minCount(n - i*i);
        if(ans < min)
            min = ans;
    }
    
    return min + 1;
}
