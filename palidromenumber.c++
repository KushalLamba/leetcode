/*                          ispalidrome in log10(n) time complexicity        */
#include <iostream>
using namespace std;
using namespace std;
bool isPalindrome(long x)
{
    if (x < 0)
    {
        return false;
    }

    long reversed = 0;
    long original = x;

    while (x > 0)
    {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    return original == reversed;
}
int main()
{
    int n;
    cout << "Enter Number: " << endl;
    cin >> n;
    cout << isPalindrome(n);
}