#include <iostream>
#include<queue>
#include<algorithm>
#include <vector>
using namespace std;
vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    int size = 0;
    if (deck.size() % 2 == 0)
    {
        size = (deck.size() / 2);
    }
    else
    {
        size = deck.size() / 2+1;
    }
    deque<int> swipper;
    for (int i = size; i < deck.size(); i++)
    {
        swipper.push_back(deck[i]);
    }
    vector<int> ans;
    for (int i = 0; i < size; i++)
    {
        swipper.push_back(swipper.front());
        swipper.pop_front();
    }
    int i = 0;
    while (!swipper.empty() && i < size)
    {
        ans.push_back(deck[i]);
        ans.push_back(swipper.front());
        swipper.pop_front();
        swipper.push_back(swipper.front());
        swipper.pop_front();
        i++;
    }
    return ans;
}
int main()
{
    cout << "Enter Number Of Elements In a Deck: " << endl;
    int n;
    cin >> n;
    vector<int> deck(n);
    for (int i = 0; i < n; i++)
    {
        cin >> deck[i];
    }
    sort(deck.begin(), deck.end());
    vector<int> ans=deckRevealedIncreasing(deck);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}