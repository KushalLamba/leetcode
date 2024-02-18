double myPow(double x, int n)
{
    if (x == 0)
    {
        return 0;
    }
    int ans=x;
    for (int i = 1; i < n; i++)
    {
        x = x * ans;
    }
    return x;
}