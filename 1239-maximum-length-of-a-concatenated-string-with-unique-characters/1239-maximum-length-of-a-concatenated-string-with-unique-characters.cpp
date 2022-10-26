class Solution {
public:
    
    int maxi = 0;
    
    bool is_unique(string& str) {
        
        int n = str.length();
        
        unordered_map<char, int> freq;
        
        for(int i = 0; i < n; i++) {
            if(freq.find(str[i]) != freq.end())
                return false;
            else 
                freq[str[i]]++;
        }
        
        return true;
    } 
    
    void helper(vector<string>& arr, int i, int n, string curr) {
        
        // check for uniqueness of string
        if(!is_unique(curr))
            return;
        
        // base case
        if(i == n) {
            // we have reached the end of array so update maxi
            if(curr.size() > maxi)
                maxi = curr.size();
            return;
        }
        
        // two options either include the current string or exclude
        helper(arr, i + 1, n, curr + arr[i]);
        helper(arr, i + 1, n, curr);
    }
    
    int maxLength(vector<string>& arr) {
        
        int n = arr.size();
        helper(arr, 0, n, "");
        return maxi;
    }
};