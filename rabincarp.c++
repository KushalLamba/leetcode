#include <iostream>
#include <climits>
using namespace std;
#define d 256
void search(string text, string patt, int q)
{
    int m = patt.length();
    int n = text.length();
    int i, j;
    int p = 0, t = 0;
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
            {
                cout << " Pattern Found AT Index: " << i << endl;
            }
        }
        if (i < n - m)
        {
            t = (d * (t - patt[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}
int main()
{
    cout << "Enter text string: " << endl;
    string text;
    getline(cin, text);
    cout << "Enter pattern String: " << endl;
    string patt;
    getline(cin, patt);
    int q = 23;
    search(text, patt, q);
}