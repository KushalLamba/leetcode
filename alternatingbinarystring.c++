#include <iostream>
using namespace std;

int minFlipsToAlternating(string S, int i) {
  int flips = 0;

  // Handle the starting character (avoid unnecessary flips at i)
  if (i == 0 && S[0] == '1') {
    flips++; // Flip the first character if it's 1
  }

  // Iterate through the string starting from position 'i+1'
  // (because we already handled the character at 'i')
  for (int j = i + 1; j < S.length(); ++j) {
    // If the current position should have a different character than what's there
    if ((j - i) % 2 == 0 && S[j] != '0') {
      ++flips; // Increment flips needed
    } else if ((j - i) % 2 != 0 && S[j] != '1') {
      ++flips; // Increment flips needed
    }
  }

  return flips;
}

int main() {
  int n;
  cin >> n;

  for(int j = 0; j < n; ++j) {
    string S;
    cin >> S;

    int i;
    cin >> i; // Input the particular position 'i'

    int min_flips = minFlipsToAlternating(S, i);

    cout << min_flips << endl;
  }

  return 0;
}
