#include <iostream>
using namespace std;
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
int main()
{
    cout << "Enter Element: " << endl;
    double x;
    cin >> x;
    cout << "Enter Power: " << endl;
    int n;
    cin >> n;
    cout<<myPow(x,n);
}