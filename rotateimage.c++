#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rotate(vector<vector<int>>& matrix)
{
    int n=matrix.size();
    int first=0;
    int last=n-1;
    while(first<last)
    {
        for(int j=0;j<n;j++)
        {
            swap(matrix[first][j],matrix[last][j]);
        }
        first++;
        last--;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(i!=j)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    return;
}
int main()
{
    cout<<"Enter Number Of rows: "<<endl;
    int row;
    cin>>row;
    cout<<"Enter Number Of Colums: "<<endl;
    int col;
    cin>>col;
    vector<vector<int>> ans(row,vector<int>(col));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>ans[i][j];
        }
    }
    rotate(ans);
    cout<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}