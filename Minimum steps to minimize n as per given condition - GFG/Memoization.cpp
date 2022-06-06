public:
	int minSteps(int N) 
	{ 
	    // Your code goes here
	   if(N == 1)
	        return 0;
	   else if(N == 2 || N == 3)
	        return 1;
	        
	   int x = INT_MAX, y = INT_MAX, z = INT_MAX;
	   
	   x = minSteps(N - 1);
	   if(N % 2 == 0)
	    y = minSteps(N/2);
	   if(N % 3 == 0)
	    z = minSteps(N/3);
	    
	   return min(x, (y, z)) + 1;
	} 
