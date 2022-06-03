#include <string>
#include <vector>
using namespace std;

vector<string> comb = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    
    if(num == 0) {
        output[0] = "";
        return 1;
    }
    
    int last = num % 10;
    int n = comb[last].size();
    
    int count = keypad(num/10, output);
    
    for(int i = 1; i < n; i++) {
        
        for(int j = 0; j < count; j++) {
            output[j + count*i] = output[j] + comb[last][i];
        }
    }
    
    for(int i = 0; i < count; i++) {
        output[i] += comb[last][0];
    }
    
    return n*count; 
}
