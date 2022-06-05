#include <iostream>
#include <string>
using namespace std;

void print_helper(string input, string output) {
	
    if(input.size() == 0) {
        cout<<output<<endl;
    }
    
    for(int i = 0; i < input.size(); i++) {
        print_helper(input.substr(0,i) + input.substr(i + 1), input[i] + output);
    }
}

void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    string output = "";
    print_helper(input, output);
}
