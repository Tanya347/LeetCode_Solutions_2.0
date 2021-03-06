int countMinStepsToOne(int n)
{
    if(n <= 1) {
        return 0;
    }
    
    int x, y = INT_MAX, z = INT_MAX;
    
    x = countMinStepsToOne(n - 1);
    if(n % 2 == 0)
    y = countMinStepsToOne(n / 2);
    if(n % 3 == 0)
    z = countMinStepsToOne(n / 3);
    
    return min(x,min(y,z)) + 1;
}
