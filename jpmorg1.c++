#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<string> maximum(string s, int i = 0) {
    vector<string> output;
    if (i == s.length() - 1) {
        output.push_back(s);
        return output;
    }
    for (int j = i; j < s.length(); j++) {
        swap(s[i], s[j]);
        vector<string> temp = maximum(s, i + 1);
        output.insert(output.end(), temp.begin(), temp.end()); // concatenate the results
        swap(s[i], s[j]);
    }
    return output;
}

int main() {
    cout << "Enter The string: " << endl;
    string s;
    cin >> s;
    string orig=s;
    vector<string> ans = maximum(s);
     int maxcount=0;
    for(int i=0;i<ans.size();i++)
    {
        int count=0;
        for(int j=0;j<orig.length();j++)
        {
            if(ans[i][j]!=orig[j])
            {
                count++;
            }
        }
        if(maxcount<count)
        {
            maxcount=count;
        }
    }
    cout<<maxcount; 
    return 0;
}
