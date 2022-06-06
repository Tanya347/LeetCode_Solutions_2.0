// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int MinSquares(int n)
	{
	    // Code here
	    if(n <= 3)
	        return n;
	    else if(sqrt(n) - floor(sqrt(n)) == 0)
	        return 1;
	    
	    int *dp = new int[n + 1];
	    
	    dp[0] = 0;
	    dp[1] = 1;
	    dp[2] = 2;
	    dp[3] = 3;
	    
	    for(int i = 4; i <= n; i++) {
	        int minimum = i;
	        for(int j = 1; j <= sqrt(n); j++) {
	            if(i - j*j >= 0)
	                minimum = min(minimum, dp[i - j*j] + 1);
	        }
	        dp[i] = minimum;
	    }
	    
	    return dp[n];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends