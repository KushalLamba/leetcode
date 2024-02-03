#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void intoro(int n, unordered_map<int, string> seen)
{
    if (n == 0)
    {
        return;
    }
    int x = 0;
    if (n <= 10)
    {
        cout << seen[n];
    }
    else if (n < 50)
    {
        x = n / 10;
        if (x < 4)
        {
            for (int i = 0; i < x; i++)
            {
                cout << "X";
            }
        }
        else
        {
            cout << "XL";
        }
        cout << seen[n % 10];
    }
    else if (n < 100)
    {
        if (n / 10 < 9)
        {
            cout << "L";
            for (int i = 5; i <= n / 10; i++)
            {
                cout << "X";
            }
        }
        else
        {
            cout << "XC";
        }
        cout << seen[n % 10];
    }
    else if (n < 500)
    {
        if (n / 10 < 40)
        {
            for (int i = 0; i < n / 100; i++)
            {
                cout << "C";
            }
        }
        else
        {
            cout << "CD";
        }
        intoro(n % 100, seen);
    }
    else if (n < 1000)
    {
        if (n / 10 < 90)
        {
            cout << "D";
            for (int i = 5; i < n / 100; i++)
            {
                cout << "C";
            }
        }
        else
        {
            cout << "CM";
        }
        intoro(n % 100, seen);
    }
    else
    {
        for (int i = 0; i < n / 1000; i++)
        {
            cout << "M";
        }
        intoro(n % 1000, seen);
    }
}
int main()
{
    unordered_map<int, string> seen;
    seen[1] = "I";
    seen[2] = "II";
    seen[3] = "III";
    seen[4] = "IV";
    seen[5] = "V";
    seen[6] = "VI";
    seen[7] = "VII";
    seen[8] = "VIII";
    seen[9] = "IX";
    seen[10] = "X";
    seen[50] = "L";
    seen[100] = "C";
    seen[500] = "D";
    seen[1000] = "M";
    cout << "Enter Number :" << endl;
    int n;
    cin >> n;
    intoro(n, seen);
}