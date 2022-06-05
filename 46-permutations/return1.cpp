#include <string>
#include <iostream>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    
    if(input.size() == 1) {
        output[0] = input[0];
        return 1;
    }
    
    int count = returnPermutations(input.substr(1), output);
    //Suppose I got bc, cb
    //now I need to attach a at all possible positions
    
    string newoutput[10000];
    int s = 0;
    
    for(int i = 0; i < input.length() ; i++) {
        
        for(int j = 0; j < count; j++) {
    		string temp = output[j].substr(0, i) + input[0] + output[j].substr(i);
            newoutput[s++] = temp;
    	}
    }
    
    for(int i = 0; i < s; i++) {
        output[i] = newoutput[i];
    }
    
    
    return s;
}
