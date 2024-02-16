
#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number Of Elements: " << endl;
    cin >> n;
    int *height = new int[n];
    cout << "Enter Height: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    int leftmax = height[0];
    int rightmax = height[n-1];
    int start = 0;
    int end = n-1;
    int sum = 0;
    while (start <= end)
    {
        if (leftmax < rightmax)
        {
            if (height[start] < leftmax)
            {
                sum += leftmax - height[start];
            }
            else
            {
                leftmax = height[start];
            }
            start++;
        }
        else
        {
            if (height[end] < rightmax)
            {
                sum += rightmax - height[end];
            }
            else
            {
                rightmax = height[end];
            }
            end--;
        }
    }
    cout << "Trapped Rain Water: " << sum << endl;
    return 0;
}
