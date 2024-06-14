#include <iostream>
#include<algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    cout << "Enter No." << endl;
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n, 0);
    vector<int> arr2(m, 0);
    cout << "Enter array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    unordered_map<int, int> counting;
    vector<int> ans;
    vector<int> sorting;
    for (int i = 0; i < arr1.size(); i++)
    {
        if (counting.count(arr1[i]) == 0)
            counting[arr1[i]] = 1;
        else
            counting[arr1[i]]++;
    }
    for (int i = 0; i < arr2.size(); i++)
    {
        for (int j = 0; j < counting[arr2[i]]; j++)
        {
            ans.push_back(arr2[i]);
        }
        counting[arr2[i]] = 0;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    for (int i = 0; i < arr1.size(); i++)
    {
        if (counting[arr1[i]] != 0)
            sorting.push_back(arr1[i]);
    }
    for (int i = 0; i < sorting.size(); i++)
    {
        cout << sorting[i] << " ";
    }
    // if (!sorting.empty())
    // {
    //     sort(sorting.begin(), sorting.end());
    //     ans.insert(ans.end(), sorting.begin(), sorting.end());
    // }
}

// 2,3,1,3,2,4,6,7,9,2,19
//[2,1,4,3,9,6]