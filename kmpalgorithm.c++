#include<iostream>
using namespace std;
void table(string patt,int m,int *lcs)
{
    lcs[0]=0;
    int pos=0;
    int i=1;
    while(i<m)
    {
        if(patt[i]==patt[pos])
        {
            pos++;
            lcs[i]=pos;
            i++;
        }
        else if(pos!=0)
        {
            pos=lcs[pos-1];
        }
        else
        {
            lcs[i]=0;
            i++;
        }
    }
}
void kmpsearch(string text,string patt)
{
    int m=patt.length();
    int n=text.length();
    int *lcs=new int[m];
    table(patt,m,lcs);
    int i=0,j=0;
    while(i<n)
    {
        if(patt[j]==text[i])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            cout<<"Position of Index is: "<<i-j<<endl;
            j=lcs[j-1];
        }
        else if(i<n && patt[j]!=text[i])
        {
            if(j!=0)
            {
                j=lcs[j-1];
            }
            else i++;
        }
    }
}
int main()
{
    cout<<"Enter text and pattern string: "<<endl;
    string text,patt;
    getline(cin,text);
    getline(cin,patt);
    kmpsearch(text,patt);
}