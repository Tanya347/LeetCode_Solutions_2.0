/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subset(int input[], int n, int output[][20]) {
    // Write your code here
	if(n == 0) {
        output[0][0] = 0;
        return 1;
    }
    
    //will return the rows filled so far
    int count = subset(input + 1, n - 1, output);
        
    //running a loop count number of times to create a copy of initial rows and insert 
    //input[0] into them
    for(int i = 0; i < count; i++) {
        //finding new size after adding one element
        int col = output[i][0] + 1;
        
        //initializing first column with size of that row
        output[i + count][0] = col;
        //Inserting input[0] in every row
        output[i + count][1] = input[0];
            
        //copying initial rows from second column onwards
        for(int j = 2; j < col+1; j++) {
            output[i + count][j] = output[i][j - 1];
        }
    }
    
    return 2*count;
}
