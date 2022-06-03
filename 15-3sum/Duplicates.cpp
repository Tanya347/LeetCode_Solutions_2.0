#include<algorithm>

int tripletSum(int *arr, int n, int num) 
{
	//Write your code here
    sort(arr,arr+n);
    int count = 0;
    
    for(int k = 0; k < n-2; k++){
        int x = num-arr[k];
        int i = k+1, j = n-1, in = 1, jm = 1;
        
        while(i<j){
            if(arr[i]+arr[j]==x){
            
                if(arr[i] == arr[j]){
                    int a = j - i + 1;
                    count += (a*(a-1))/2;
                    break;
                }
                
                else if(arr[i+1] == arr[i])
                    i++, in++;
                
                else if(arr[j-1] == arr[j])
                    j--, jm++;
                
                else{
                    count += in*jm;
                    in = 1, jm = 1;
                    i++, j--;
                }
            }
            
            else if(arr[i]+arr[j]>x)
                j--;
            else
                i++;
        }
    }
    return count;
}
