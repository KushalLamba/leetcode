/*                             zigzag conversion question 6                                                                  */
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string convert(string s,int numrows)
{
 if(numrows==1 || numrows>=s.size())
 return s;
  vector<string> rows(numrows);
  int row=0;
  bool step=false;
  for(int i=0;i<s.length();i++)
  {
    rows[row]+=s[i];
    if(row==0 || row==numrows-1)
    {
       step=!step;
    }
    row+=step?1:-1;
  }
  string result;
  for(int i=0;i<rows.size();i++)
  {
    result+=rows[i];
  }
  return result;
}
int main()
{
    string s;
    cout<<"Enter String: "<<endl;
    cin>>s;
    cout<<"Enter Number of Rows: "<<endl;
    int numrow;
    cin>>numrow;
    string result=convert(s,numrow);
    cout<<result;
}