#include <iostream>
#include<vector>
#include <queue>
using namespace std;
int main()
{
    int n;
    cout << "Enter No. of Elements: " << endl;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    priority_queue<int,vector<int>,greater<int>> minheap;
    for (int i = 0; i < n; i++)
    {
        minheap.push(arr[i]);
    }
    int sum=0;
    while (minheap.size()>=2)
    {
        int first=minheap.top();
        minheap.pop();
        int second=minheap.top();
        minheap.pop();
        sum+=first+second;
        minheap.push(first+second);
    }
    minheap.pop();
    cout<<sum;
}