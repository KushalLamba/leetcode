#include <iostream>
using namespace std;

int main() {
    int n = 4; // Example: Generate 5 iterations of Count and Say sequence
    string s = "1";
    string ans = "";

    for (int j = 1; j < n; j++) {
        ans = "";
        char c = s[0];
        int count = 1;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == c) {
                count++;
            } else {
                ans += to_string(count) + c;
                c = s[i];
                count = 1;
            }
        }

        ans += to_string(count) + c;
        s = ans;
    }

    cout << s << endl; // Output the generated sequence
    return 0;
}
