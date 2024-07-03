#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n%4==0) cout<< n;
    else if(n%4==1) cout<< 1;
    else if(n%4==3) cout<< 0;
    else cout<< n+1;
}