#include <iostream>
using namespace std;

int main() {
    cout << "Enter the number: " << endl;
    int n;
    cin >> n;

    cout << "Enter i: " << endl;
    int i;
    cin >> i;

    // Corrected condition
    if ((n & (1 << i)) == 0) 
        cout << "false" << endl;
    else 
        cout << "true"<< endl;

    return 0;
}
