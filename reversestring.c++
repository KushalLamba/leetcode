#include <iostream>
#include<algorithm>
#include <cstring>
using namespace std;
int main()
{
    string str;
    cout << "Enter String: " << endl;
    getline(cin,str);
    cout<<str[str.length()-1];
}