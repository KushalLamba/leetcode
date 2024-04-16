#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int area1(vector<vector<int>> &matrix)
{
    vector<int> areas;
    for (int i = 1; i <3; i++)
    {
        int maxarea = matrix[i][0];
        int area = 0;
        int value = matrix[i][0];
        int index = 0;
        int minvalue=matrix[i][0];
        for (int j = 1; j < matrix[i].size(); j++)
        {
            cout<<"minvalue value maxarea index"<<endl;
            cout<<minvalue<<" "<<value<<" "<<maxarea<<" "<<index<<endl;
            value=min(matrix[i][j], matrix[i][j - 1]);
            if(minvalue>value)
            {
                index=j;
            }
            area=value*(j+1-index);
            if (area > maxarea)
            {
                maxarea = area;
            }
        }
        //cout << maxarea << endl;
        areas.push_back(maxarea);
    }
    return 0;
}
int maximalRectangle(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size() && i != 0; j++)
        {
            if (matrix[i][j] != 0)
            {
                matrix[i][j] += matrix[i - 1][j];
            }
        }
    }
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size() && i != 0; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return area1(matrix);
}
int main()
{
    cout << "enter rows and col: " << endl;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << maximalRectangle(matrix);
    return 0;
}