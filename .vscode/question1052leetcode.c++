#include <iostream>
#include <vector>
using namespace std;
int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
{
    int i = 0;
    int maxsum = 0;
    int count = 0;
    int startindex = 0;
    int sum = 0;
    int sum0=0;
    while (i < customers.size())
    {
        if(grumpy[i]==1) sum+=customers[i];
        if(grumpy[i]==0) sum0+=customers[i];
        maxsum=max(maxsum,sum);
        if(count>=minutes)
        {
            if(grumpy[startindex]==1) sum-=customers[startindex];
            startindex++;
            cout<<startindex<<endl;
        }
        i++;
        count++;
        //cout<<sum<<endl;
    }
    cout<<sum0<<endl;
    cout<<maxsum<<endl;
    return maxsum+sum0;
}
int main()
{
    cout << "Enter Number Of Elements: " << endl;
    int n;
    cin >> n;
    cout << "Enter Customers array: " << endl;
    vector<int> customers(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> customers[i];
    }
    vector<int> grumpy(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> grumpy[i];
    }
    int minutes;
    cin >> minutes;
    cout << maxSatisfied(customers, grumpy, minutes);
}