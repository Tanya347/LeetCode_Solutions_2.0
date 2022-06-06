//Coding ninjas 1
#include<cmath>				
				
int balancedBTs(int n) {				
// Write your code here				
if(n == 0 || n == 1)				
return 1;				
				
int mod = (int)pow(10, 9) + 7;				
int x = balancedBTs(n - 1);				
int y = balancedBTs(n - 2);				
				
int ans1 = (int)(((long)x * x) % mod);				
int ans2 = (int)((2 *(long)x * y) % mod);				
long ans = (ans1 + ans2) % mod;				
				
return ans;				
}				
				
//coding ninjas 2	
int balancedBTs(int n) {				
if(n <= 1)				
return 1;				
				
int mod = (int)pow(10, 9) + 7;				
int x = balancedBTs(n - 1);				
int y = balancedBTs(n - 2);				
				
long long int ans1 = ((long long int)x * x) % mod;				
long long int ans2 = (2* (long long int)x * y) % mod;				
long long int ans = (ans1 + ans2) % mod;				
				
return ans;				
}				
				
//geeks for geeks
long long int countBT(int h) {				
// code here				
				
if(h <= 1)				
return 1;				
				
int mod = pow(10,9) + 7;				
long long int x = countBT(h - 1);				
long long int y = countBT(h - 2);				
				
long long int ans1 = (x*x) % mod;				
long long int ans2 = (2*x*y) % mod;				
long long int ans = (ans1 + ans2) % mod;				
				
return ans;				
}				
