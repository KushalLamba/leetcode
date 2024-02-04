// #include <iostream>
// #include <vector>
// #define mod 10000000007
// using namespace std;
/*-----------------------ONLY USING RCURSION-------------------*/
// long long int Derangement(int n)
// {
//     if (n == 1)
//     {
//         return 0;
//     }
//     if (n == 2)
//     {
//         return 1;
//     }
//     long long int ans = ((n - 1)%mod)*(Derangement(n-1)+Derangement(n-2));
//     return ans;
// }
/*-------------------USING RECURSION AND MEMORIZATION-------------------*/
// long long int Derangement(int n,vector<long long int>& dp)
// {
//     if(n==1) return 0;
//     if(n==2) return 1;
//     if(dp[n]!=-1)
//     {
//         return dp[n];
//     }
//     dp[n]=(((n - 1)%mod)*(((Derangement(n-1,dp))%mod)+((Derangement(n-2,dp))%mod))%mod)%mod;
//     return dp[n];
// }
/*--------------------WITHOUT USING RECURSION-----------------------*/
// long long int Derangement(int n)
// {
//     vector<long long int> dp(n+1,0);
//     dp[1]=0;
//     dp[2]=1;
//     for (int i = 3; i <=n; i++)
//     {
//         long long int first=(i-1)%mod;
//         long long int second=dp[i-1]%mod;
//         long long int third=dp[i-2]%mod;
//         long long int sum=(second+third)%mod;
//         dp[i]=(first*sum)%mod;
//     }
//     return dp[n];
// }
/*-----------------------BEST SOLUTION-----------------------------*/
// long long int Derangement(int n)
// {
//     long long int prev1=0;
//     long long int prev2=1;
//     for(int i=3;i<=n;i++)
//     {
//         long long int curr=(((i-1)%mod)*((prev1%mod)+(prev2%mod)))%mod;
//         prev1=prev2;
//         prev2=curr;
//     }
//     return prev2;
// }

// int main()
// {
//     cout << "Enter Number Of Elements: " << endl;
//     int n;
//     cin >> n;
//     // vector<long long int> dp(n+1,-1);
//     cout << Derangement(n /*,dp*/);
// }