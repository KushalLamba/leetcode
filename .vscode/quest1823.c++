#include <bits/stdc++.h>
using namespace std;
int answer(int n,int k)
{
    if(n==1) return 0;
    int index=(answer(n-1,k)+k)%n;
    cout<<n<<endl;
    return index;
}
int main() {
    cout << "Enter Number Of Friends: " << endl;
    int n;
    cin >> n;
    int k;
    cout << "Enter Value of K: " << endl;
    cin >> k;
    cout<<answer(n,k)+1;
}
