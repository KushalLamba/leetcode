#include <iostream>
#include <vector>
using namespace std;
int maxDistance(vector<int> &position, int m)
{
    int left = 0;
    int right = position.size() - 1;
    int minf = position[right] - position[left];
    cout<<left<<endl;
    cout<<right<<endl;
    cout<<minf<<endl;
    if (m == 2)
        return minf;
    m-=2;
    while (left < right && m != 0)
    {
        int mid = (left+right)/2;
        cout<<mid<<endl;
        int leftd = position[mid] - position[left];
        int rightd = position[right] - position[mid];
        if (leftd > rightd)
        {
            right = mid;
            minf = rightd;
        }
        else
        {
            left = mid;
            minf = leftd;
        }
        m--;
        cout<<minf<<endl;
    }
    return minf;
}
int main()
{
    cout << "Enter Number OF elements: " << endl;
    int n;
    cin >> n;
    vector<int> position(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> position[i];
    }
    cout << "Enter Number Of Balls: " << endl;
    int m;
    cin >> m;
    cout<<maxDistance(position,m);
}