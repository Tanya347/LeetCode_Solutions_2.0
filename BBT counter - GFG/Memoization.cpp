//coding ninjas

#include<cmath>

int balancedBTs_helper(int *ans, int n) {
    
    if(n == 0 || n == 1)
        return 1;
    
    int mod = (int) pow(10, 9) + 7;
    
    if(ans[n] != -1)
        return ans[n];
    
    int x = balancedBTs_helper(ans, n - 1);
    int y = balancedBTs_helper(ans, n - 2);
    
    ans[n - 1] = x % mod;
    ans[n - 2] = y % mod;
    
    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2*(long)(x)*y) % mod);
    
    ans[n] = (temp1 + temp2) % mod;
     
    
    return ans[n];
} 

int balancedBTs(int n) {
    
    int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++) {
        ans[i] = -1;
    }
    return balancedBTs_helper(ans, n);
}

//geeks for geeks

long long int countBT(int h, long long int* mem) {
        if(h <= 1)
            return 1;
            
        if(mem[h] != -1)
            return mem[h];
            
        int mod = pow(10,9) + 7;
        long long int x = countBT(h - 1);
        long long int y = countBT(h - 2);
        
        mem[h - 1] = x % mod;
        mem[h - 2] = y % mod;
        
        long long int ans1 = (x*x) % mod;
        long long int ans2 = (2*x*y) % mod;
        long long int ans = (ans1 + ans2) % mod;
        
        mem[h] = ans;
        return ans;
    }
    
    long long int countBT(int h) { 
        // code here
        
        long long int *ans = new long long int[h + 1];
        for(int i = 0; i <= h; i++) {
            ans[i] = -1;
        }   
        return countBT(h, ans);
    }




