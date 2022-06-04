#include<iostream>
using namespace std;

void print_helper(int input[], int size, int* output, int m) {
	if(size == 0) {
        for(int i = 0; i < m; i++)
            cout<<output[i]<<" ";
        cout<<endl;
        return;
    }    
    
    int newoutput[m + 1];
    for(int i = 0; i < m; i++) {
        newoutput[i] = output[i];
    }
    
    newoutput[m] = input[0];
    
    print_helper(input + 1, size - 1, newoutput, m + 1);
    print_helper(input + 1, size - 1, output, m);
}

void printSubsetsOfArray(int input[], int size) {
	int *output = new int[size];
    print_helper(input, size, output, 0);
}
