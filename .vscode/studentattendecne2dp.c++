#include <iostream>
#include <vector>
using namespace std;
/* approch using simple dp
 int checkRecord(int n,int abs=0,int late=0) {
        if(n==0)return 1;
        if(abs>1 || late>2) return 0;
        int p=checkRecord(n-1,abs,0);
        int a=checkRecord(n-1,abs+1,0);
        int l=checkRecord(n-1,abs,late+1);
        return p+a+l;
    }
*/
int checkRecord(int n)
{
    int m = 1e9 + 7;
    vector<vector<vector<int>>> dp(100000001, vector<vector<int>>(2, vector<int>(3, 0)));

    // base case n==0
    for (int a = 0; a <= 1; a++)
    {
        for (int l = 0; l <= 2; l++)
        {
            dp[0][a][l] = 1;
        }
    }
    for (int p = 1; p < n; p++)
    {
        for (int a = 0; a <= 1; a++)
        {
            for (int l = 0; l <= 2; l++)
            {
                long result = 0;
                result += dp[p][a][0];
                if (a <= 1)
                    result += dp[p - 1][a + 1][0];
                if (l <= 2)
                    result += dp[p - 1][a][l + 1];
                dp[p][a][l] = result % m;
            }
        }
    }
    return dp[n][0][0];
}
int main()
{
    cout << "Enter Value Of Days: " << endl;
    int n;
    cin >> n;
}