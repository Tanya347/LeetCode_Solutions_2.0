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
            
        if(mem[sum][i] != -1)
        return mem[sum][i];
        
        if(arr[i] > sum)
            mem[sum][i] = isSubsetSum_Helper(arr, sum, i + 1, mem);
        else {
            int x = isSubsetSum_Helper(arr, sum - arr[i], i + 1, mem);
            int y = isSubsetSum_Helper(arr, sum, i + 1, mem);
            
            mem[sum][i] = x || y;
        }
        
        return mem[sum][i];
    
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>> mem(sum + 1, vector<int>(arr.size() + 1, -1));
        return isSubsetSum_Helper(arr, sum, 0, mem);
    }
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