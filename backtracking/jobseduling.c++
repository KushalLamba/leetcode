#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class job
{
    public:
    int deadline;
    int profit;
    char id;
    job(char id,int deadline,int profit)
    {
        this->id=id;
        this->deadline=deadline;
        this->profit=profit;
    }
};
bool comparision(job a,job b)
{
    return a.profit>b.profit;
}
void printjobseduling(job arr[],int n)
{
    sort(arr,arr+n,comparision);
    int result[n];
    bool check[n];
    for(int i=0;i<n;i++)
    {
        check[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,arr[i].deadline-1);j>=0;j--)
        {
            if(!check[j])
            {
                result[j]=i;
                check[j]=true;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(check[i])
        {
            cout<<arr[result[i]].id<<" ";
        }
    }
}
int main()
{
  job arr[] = { job('a', 2, 100),
                  job('b', 1, 19),
                  job('c', 2, 27),
                  job('d', 1, 25),
                  job('e', 3, 15) };
  int n = sizeof(arr) / sizeof(arr[0]);
  printjobseduling(arr,n);
}