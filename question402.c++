#include <iostream>
#include <string>
using namespace std;

string removeKdigits(string num, int k) {
    if (num.empty() || k == num.size())
        return "0";

    string s;
    int size1 = num.size() - k;
    s.push_back(num[0]);

    for (int i = 1; i < num.size(); i++) {
        while (!s.empty() && s.back() > num[i] && k > 0) {
            s.pop_back();
            k--;
        }
        s.push_back(num[i]);
    }

    // Handle cases where the remaining k digits are larger than the rest of the number
    while (s.size() > size1) {
        s.pop_back();
    }

    // Remove leading zeros
    int i = 0;
    while (i < s.size() && s[i] == '0') {
        i++;
    }
    s = s.substr(i);

    return s.empty() ? "0" : s;
}

int main() {
    string num = "1432219";
    int k = 3;
    cout << removeKdigits(num, k) << endl;
    return 0;
}
