// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapsack(int* weights, int* values, int n, int W, int** mem) {
        if(n == 0 || W <= 0)
            return 0;
            
        if(mem[W][n] != -1)
            return mem[W][n];
        
        if(W < weights[0]) {
            mem[W][n] = knapsack(weights + 1, values + 1, n - 1, W, mem);
        }
        
        else {
            int x = values[0] + knapsack(weights + 1, values + 1, n - 1, W - weights[0], mem);
            int y = knapsack(weights + 1, values + 1, n - 1, W, mem);
            mem[W][n] = max(x, y);
        }
        
        return mem[W][n];
    }

    int knapSack(int maxWeight, int weight[], int value[], int n) 
    { 
       // Your code here
       int **mem = new int*[maxWeight + 1];
    
        for(int i = 0; i < maxWeight + 1; i++) {
            mem[i] = new int[n + 1];
            for(int j = 0; j < n + 1; j++)
                mem[i][j] = -1;
        }
    
        return knapsack(weight, value, n, maxWeight, mem);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends