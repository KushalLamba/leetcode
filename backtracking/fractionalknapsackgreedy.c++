#include<bits/stdc++.h>
using namespace std;
class carry
{
    public:
    int weight;
    int profit;
    carry(int profit,int weight)
    {
        this->profit=profit;
        this->weight=weight;
    }
};
static bool cmp(carry a,carry b)
{
    double r1=(double)a.profit/(double)a.weight;
    double r2=(double)b.profit/(double)b.weight;
    return r1>r2;
}
double knapsack(carry arr[],int n,int maxweight)
{
    sort(arr,arr+n,cmp);
    double ans=0.0;
    for(int i=0;i<n;i++)
    {
        if(maxweight>=arr[i].weight)
        {
            ans+=arr[i].profit;
            maxweight-=arr[i].weight;
        }
        else
        {
            ans+=arr[i].profit*((double)maxweight/(double)arr[i].weight);
            break;
        }
    }
    return ans;
}
int main()
{
    int W = 50;
    carry arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << knapsack(arr, N,W);
    return 0;
}