#include <iostream>

using namespace std;

bool kperfect(int pos, int i)
{
    return ((pos*i) - pos - i) % 2 == 0;
}
int finder(int n, int m, int k, int pos = 0)
{
    if (n == 0)
    {
        if (k == 0) return 1;
        return 0;
    }
    int ans=0;
    for (int i = 1; i <= m; i++)
    {
        int newk=k-(pos!=0 && kperfect(pos,i));
        ans += finder(n-1, m,newk, i);
    }
    return ans;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    cout << finder(n, m, k);
    return 0;
}