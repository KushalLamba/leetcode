#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string largestNumber(int num) {
  string numStr = to_string(num);

  // Iterate through all adjacent pairs
  for (int i = 0; i < numStr.size() - 1; i++) {
    // Check if digits have the same parity (both even or both odd)
    if ((numStr[i] - '0') % 2 == (numStr[i + 1] - '0') % 2) {
      // Find the largest digit among current and next
      char largerDigit = max(numStr[i], numStr[i + 1]);

      // Swap if the larger digit is not in the current position
      if (numStr[i] != largerDigit) {
        swap(numStr[i], numStr[i + 1]);
      }
    }
  }

  return numStr;
}

int main() {
  int num;
  cout << "Enter a number: ";
  cin >> num;

  string largest = largestNumber(num);
  cout << "Largest number that can be formed: " << largest << endl;

  return 0;
}