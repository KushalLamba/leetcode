// #include <iostream>
// #include <vector>
// using namespace std;
// string ans1(vector<char> ans, int &k, vector<bool> &visited,string s="")
// {

//     if(s.size()==ans.size())
//     {
//         k--;
//         if(k==0) return s;
//         return "";
//     }
//     string result;
//     for (int j = 0; j < ans.size(); j++)
//     {
//         if (!visited[j])
//         {
//             visited[j]=true;
//             result=ans1(ans, k,visited,s+ans[j]);
//             if(!result.empty()) return result;
//             visited[j]=false;
//         }
//     }
//     return "";
// }
// string getPermutation(int n, int k)
// {
//     vector<char> ans;
//     for (int i = 1; i <= n; i++)
//     {
//         ans.push_back(char('0' + i));
//     }
//     vector<bool> visited(ans.size(),false);
//     return ans1(ans,k,visited);
// }
// int main()
// {
//     cout<<"Enter the number: "<<endl;
//     int n;
//     cin>>n;
//     cout<<"Enter Position: "<<endl;
//     int k;
//     cin>>k;
//     cout<<getPermutation(n,k);
//     return 0;
// }

// SECOND APPROCH(N^2)
#include <iostream>
#include <vector>
using namespace std;

// Calculate factorial of n
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Generate k-th permutation
string getPermutation(int n, int k) {
    vector<int> digits;
    for (int i = 1; i <= n; i++) {
        digits.push_back(i);
    }
    
    string sol = "";
    k--; // Adjust k to zero-based index
    
    while (n > 0) {
        int fac = factorial(n - 1);
        int index = k / fac;
        sol += char('0' + digits[index]);
        digits.erase(digits.begin() + index); // Erase selected digit
        k %= fac; // Update k for next iteration
        n--; // Decrease the remaining size
    }
    
    return sol;
}

int main() {
    cout << "Enter Number: " << endl;
    int n;
    cin >> n;
    cout << "Enter Value Of K: " << endl;
    int k;
    cin >> k;
    cout << getPermutation(n, k) << endl;
    return 0;
}
