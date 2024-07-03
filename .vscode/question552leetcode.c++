#include <iostream>
#include <vector>
using namespace std;

int checkRecord(int n, int abs = 0, int late = 0)
{
    if (n == 0)
        return 1;
    if (abs >=1 || late >=2)
        return 0;
    int a=0;
    int p = checkRecord(n - 1, abs, 0);
    if(a<2){
    a = checkRecord(n - 1, abs + 1, 0);}
    int l = checkRecord(n - 1, abs, late + 1);
    return p + a + l;
}

int main()
{
    cout << "Enter Number Of Days: " << endl;
    int n;
    cin >> n;
    cout << "Total number of valid sequences: " << checkRecord(n) << endl;
    return 0;
}
