#include <iostream>
#include<vector>
#include<queue>
using namespace std;
int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    deque<int> ans;
    for (int i = 0; i < students.size(); i++)
    {
        ans.push_back(students[i]);
    }
    int i = 0;
    int count = 0;
    while (!ans.empty())
    {
        if (count == ans.size())
        {
            break;
        }
        if (sandwiches[i] == ans.front())
        {
            count = 0;
            i++;
            ans.pop_front();
        }
        else
        {
            ans.push_back(ans.front());
            ans.pop_front();
            count++;
        }
    }
    return ans.size();
}
int main()
{
    cout<<"Enter Number Of Student: "<<endl;
    int n;
    cin>>n;
    vector<int> students(n);
    vector<int> sandwiches(n);
    for(int i=0;i<n;i++)
    {
        cin>>students[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>sandwiches[i];
    }
    cout<<countStudents(students,sandwiches);
    return 0;
}