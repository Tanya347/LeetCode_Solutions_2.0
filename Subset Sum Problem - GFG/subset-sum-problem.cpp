// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int isSubsetSum_Helper(vector<int>arr, int sum, int i, vector<vector<int>>& mem) {
        
        if(i == arr.size()) {
            if(sum == 0)
                return 1;
            else 
                return 0;
        }
        
        if(sum == 0)
            return 1;
        
        if(sum < 0)
            return 0;
            
        if(mem[i][sum] != -1)
        return mem[i][sum];
        
        if(arr[i] > sum)
            mem[i][sum] = isSubsetSum_Helper(arr, sum, i + 1, mem);
            
        else {
            int x = isSubsetSum_Helper(arr, sum - arr[i], i + 1, mem);
            int y = isSubsetSum_Helper(arr, sum, i + 1, mem);
            
            mem[i][sum] = x || y;
        }
        
        return mem[i][sum];
    
    }
    
    bool isSubsetSum(vector<int> arr, int sum) {
        vector<vector<int>> dp(arr.size() + 1, vector<int>(sum + 1, -1));
        return isSubsetSum_Helper(arr, sum, 0, dp);
    }
    
    // bool isSubsetSum(vector<int>arr, int sum){
    //     // code here 
    //     if(sum == 0)
    //     return 1;
        
    //     vector<vector<bool>> dp(arr.size() + 1, vector<bool>(sum + 1));
        
    //     for(int i = 0; i <= arr.size(); i++)
    //         dp[i][0] = true;
    
    //     for(int i = 1; i <= sum; i++)
    //         dp[0][i] = false;
        
    //     for(int i = 1; i <= arr.size(); i++) {
    //         for(int j = 1; j <= sum; j++) {
    //             if(arr[i - 1] > j) {
    //                 dp[i][j] = dp[i - 1][j];
    //             } else {
    //                 dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
    //             }
    //         }
    //     }
        
    //     return dp[arr.size()][sum];
    // }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends