#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, h, t;
    cin >> s >> h >> t;

    if (s.size() + h.size() != t.size())
    {
        cout << "NO";
        return 0;
    }

    int freq[256] = {0};

    for (char c : s)
        freq[c]++;

    for (char c : h)
        freq[c]++;

    for (char c : t)
        freq[c]--;

    for (int x : freq)
    {
        if (x != 0)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}