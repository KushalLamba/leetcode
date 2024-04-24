#include<iostream>
#include<stack>
using namespace std;
// bool checkValidParenthesis(string s)
// {
//     stack<int> star,open;
//     for(int i=0;i<s.size();i++)
//     {
//         if(s[i]=='(')
//         {
//             open.push(i);
//         }
//         else if(s[i]=='*')
//         {
//             star.push(i);
//         }
//         else
//         {
//             if(!open.empty())
//             {
//                 open.pop();
//             }
//             else if(!star.empty())
//             {
//                 star.pop();
//             }
//             else{
//                 return false;
//             }
//         }
//     }
//     while(!open.empty() && !star.empty())
//     {
//         if(open.top()>star.top())
//         {
//             return false;
//         }
//         open.pop();
//         star.pop();
//     }
//     return open.empty();
// }
bool checkValidParenthesis(string s)
{
    int leftmax=0;
    int leftmin=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            leftmin++;
            leftmax++;
        }
        else if(s[i]==')')
        {
            leftmax--;
            leftmin--;
        }
        else{
            leftmax++;
            leftmin--;
        }
        if(leftmax<0) return false;
        if(leftmin<0) leftmin=0;
    }
    return leftmin==0;
}
int main()
{
    cout<<"Enter the string: "<<endl;
    string s;
    getline(cin,s);
    if(checkValidParenthesis(s))
    {
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
}