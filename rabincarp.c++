#include <iostream>
#include <climits>
#define d 256
using namespace std;
void search(string text, string patt, int q)
{
    int n = text.length();
    int m = patt.length();
    int p = 0, t = 0;
    int i, j;
    int h = 1;
    for (i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }
    for (i = 0; i < m; i++)
    {
        p = (p * d + patt[i]) % q;
        t = (t * d + text[i]) % q;
    }
    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (patt[j] != text[i + j])
                    break;
            }
            if (j == m)
                cout << "Pattern Found At Index: " << i << endl;
        }
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = t + q;
        }
    }
}
int main()
{
    cout << "Enter Text: " << endl;
    string text;
    getline(cin, text);
    cout << "Enter Pattern: " << endl;
    string patt;
    getline(cin, patt);
    int q = INT_MAX;
    search(text, patt, q);
}