#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> comb = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void print_helper(string output, int num) {
    
    if(num == 0) {
        cout<<output<<endl;
        return;
    }
    
    int n = comb[num%10].size();
    
    for(int i = 0; i < n; i++) {
        print_helper(comb[num%10][i] + output, num/10);
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output;
    print_helper(output, num);
}
