bool isSubsetSum_Helper(vector<int>arr, int sum, int i) {
        if(sum == 0)
            return true;
        
        if(i == arr.size()) {
            if(sum == 0)
                return true;
            else 
                return false;
        }
        
        if(sum < 0)
            return false;
            
        if(arr[i] > sum)
        return isSubsetSum_Helper(arr, sum, i + 1);
        
        else {
            bool x = isSubsetSum_Helper(arr, sum - arr[i], i + 1);
            bool y = isSubsetSum_Helper(arr, sum, i + 1);
        
            return x || y;
        }
    
    }
    
bool isSubsetSum(vector<int>arr, int sum){
    // code here 
    return isSubsetSum_Helper(arr, sum, 0);
}
