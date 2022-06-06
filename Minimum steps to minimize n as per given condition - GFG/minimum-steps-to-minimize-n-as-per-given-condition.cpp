// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minSteps(int N) 
	{ 
	    // Your code goes here
	    int *dp = new int[N + 1];
	    dp[1] = 0;
	    dp[2] = 1;
	    dp[3] = 1;
	    
	    for(int i = 4; i <= N; i++) {
	        
	        int ans1 = N, ans2 = N, ans3 = N;
            ans1 = dp[i-1];
        
            if(i % 2 == 0) {
                ans2 = dp[i/2];
            }
        
            if(i % 3 == 0) {
                ans3 = dp[i/3];
            }
        
            dp[i] = min(ans1, min(ans2, ans3)) + 1;
	    }
	    
	    return dp[N];
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.minSteps(n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends