// #include <iostream>
// #include <unordered_map>
// using namespace std;
// int main()
// {
//     cout << "Enter the roman Number: " << endl;
//     string s;
//     cin >> s;
//     unordered_map<char, int> seen;
//     seen['I'] = 1;
//     seen['V'] = 5;
//     seen['X'] = 10;
//     seen['L'] = 50;
//     seen['C'] = 100;
//     seen['D'] = 500;
//     seen['M'] = 1000;
//     int sum=0;
//     for (int i = 0; i < s.length() - 1; i++)
//     {
//         if (seen[s[i]] >= seen[s[i + 1]])
//         {
//             sum +=seen[s[i]];
//         }
//         else{
//             sum-=seen[s[i]];
//         }
//     }
//     cout<<sum+seen[s[s.length()-1]];
// }
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cout<<"Enter The Number You Want In Roman"<<endl;
	cin>>a;
	int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i=12;
    while(a>0)
    {
    	int number=a/num[i];
    	a=a%num[i];
    	while(number>0)
    	{
    		cout<<sym[i];
    		number--;
    	}
    	i--;
    } 

}