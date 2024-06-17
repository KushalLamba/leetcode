#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
bool isNStraightHand(vector<int> &hand, int groupSize)
{
    sort(hand.begin(), hand.end());
    unordered_map<int, int> check;
    for (int i = 0; i < hand.size(); i++)
    {
        check[hand[i]]++;
    }
    for (int i = 0; i <=hand.size()-groupSize; i++)
    {
        int x = hand[i];
        if (check[x] != 0)
        {
            check[x]--;
            cout<<x<<endl;
            for (int j = 1; j < groupSize; j++)
            {
                if (check[x + j] == 0)
                    return false;
                cout<<x+j<<endl;
                check[x + j]--;
            }
        }
    }
    return true;
}
int main()
{
    cout << "Enter Number Of Elements: " << endl;
    int n;
    cin >> n;
    cout << "Enter Hands Array: " << endl;
    vector<int> hand(n, 0);
    for (int i = 0; i < n; i++)
        cin >> hand[i];
    cout << "Enter group size: " << endl;
    int groupsize;
    cin >> groupsize;
    cout<<isNStraightHand(hand,groupsize);
}