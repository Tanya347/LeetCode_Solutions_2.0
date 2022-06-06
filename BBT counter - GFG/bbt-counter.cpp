// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int countBT(int h) { 
        // code here
        if(h <= 1)
            return 1;
            
        long long int *dp = new long long int[h + 1];
        int mod = pow(10, 9) + 7;
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= h; i++) {
            
            dp[i] = (dp[i - 1]*(dp[i - 1] + 2*dp[i - 2])) % mod;
            
        }
        
        return dp[h];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends