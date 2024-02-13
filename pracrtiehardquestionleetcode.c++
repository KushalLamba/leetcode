#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> seen;
    cout << "Enter The string: " << endl;
    string str;
    cin >> str;
    cout << "Enter Number of Elements: " << endl;
    int nwords;
    cin >> nwords;
    vector<string> words(nwords, "");
    for (int i = 0; i < nwords; i++)
    {
        cin >> words[i];
        if (seen.count(words[i]) == 0)
        {
            seen[words[i]] = 1;
        }
        else
        {
            seen[words[i]] += 1;
        }
    }

    int lword = words[0].length();
    int first = 0;
    int last = 0;
    int count = 0;

    for (int i = 0; i <= str.length() - (lword * nwords); i++)
    {
        first = i;
        string check = str.substr(first, lword);
        if (seen[check] > 0)
        {
            while (seen[check] > 0)
            {
                cout << check << " ";
                count++;
                seen[check] -= 1;

                // Update first and last for the next substring
                first = lword + first;

                // Check if we've reached the end of the string
                if (last > str.length())
                {
                    break;
                }

                check = str.substr(first, lword);
            }
            for (int i = 0; i < nwords; i++)
            {
                cin >> words[i];
                if (seen.count(words[i]) == 0)
                {
                    seen[words[i]] = 1;
                }
                else
                {
                    seen[words[i]] += 1;
                }
            }
        }
        else
        {
            continue;
        }
        cout << endl;
    }

    return 0;
}
