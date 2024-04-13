#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
int maximalRectangle(vector<vector<int>> &matrix)
{
    vector<int> row;
    int sum = 0;
    int maxsum=0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                sum = 0;
            }
            else
            {
                sum = sum + 1;
            }
            if(sum>maxsum)
            {
                maxsum=sum;
            }
        }
        row.push_back(maxsum);
        sum=0;
        maxsum=0;
    }
    int max = 0;
    for (int i = 0; i < row.size(); i++)
    {
        cout<<(row.size() - 1 - i)<<" "<<row[i]<<endl;
        int value = (row.size() - 1 - i) * row[i];
        if (max < value)
        {
            max = value;
        }
    }
    return max;
}
int main()
{
    cout << "enter rows and col: " << endl;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout<<maximalRectangle(matrix);
    return 0;
}