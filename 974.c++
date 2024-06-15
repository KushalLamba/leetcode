#include<iostream>
#include<vector>
using namespace std;
int main()
{
    cout<<"Enter Number Of Elements: "<<endl;
    int n;
    cin>>n;
    cout<<"Enter Elements Of Array: "<<endl;
    vector<int> num(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cout<<"Enter Value of k: "<<endl;
    int k;
    cin>>k;
    subarrdivbyk(num,k,0,num[0]);
}
//4 5 0 -2 -3 1