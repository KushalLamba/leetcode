#include <iostream>
using namespace std;
#include <climits>
int reverse(int x)
{
    int flag = 0;
    if (x < 0)
    {
        flag = 1;
        x = abs(x - 0);
    }
    int y = 0;
    while (x != 0)
    {
        y = y * 10 + x % 10;
        x = x / 10;
    }
    if (flag == 1)
    {
        y = -y;
    }
    if (y > (INT_MAX / 10)  || y < (INT_MIN / 10))
    {
        return 0;
    }

    return y;
}
int main()
{
    int n;
    cout << "Enter Number: " << endl;
    cin >> n;
    cout << reverse(n);
}