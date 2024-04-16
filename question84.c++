#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int largestRectangleArea(vector<int> &heights)
{
    stack<int> index;
    index.push(0);
    int area = 0;
    int maxarea = heights[0];
    for (int i = 1; i < heights.size(); i++)
    {
        int value = min(heights[i], heights[i - 1]);
        while (!index.empty())
        {
            if (value <= heights[index.top()])
            {
                index.pop();
            }
            else
            {
                break;
            }
        }
        if (heights[i] >= heights[i - 1])
        {
            index.push(i - 1);
        }
        else
        {
            index.push(i);
        }
        int  p= heights.size();
        while (!index.empty())
        {
            int topHeight = heights[index.top()];
            index.pop();
            int width = index.empty() ? p : p - index.top() - 1;
            maxarea = max(maxarea, topHeight * width);
        }
    }
    cout << index.top() << endl;
    return maxarea;
}
int main()
{
    cout << "Enter Number Of Heights: " << endl;
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    cout << largestRectangleArea(heights);
}