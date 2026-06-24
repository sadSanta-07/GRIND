#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    unordered_map<char,int> need;
    unordered_map<char,int> window;

    for(char c : t)
        need[c]++;

    int required = need.size();
    int formed = 0;

    int left = 0;

    int minLen = INT_MAX;
    int start = 0;

    for(int right = 0; right < s.size(); right++)
    {
        char ch = s[right];

        window[ch]++;

        if(need.count(ch) &&
           window[ch] == need[ch])
        {
            formed++;
        }

        while(formed == required)
        {
            if(right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                start = left;
            }

            char remove = s[left];

            window[remove]--;

            if(need.count(remove) &&
               window[remove] < need[remove])
            {
                formed--;
            }

            left++;
        }
    }

    if(minLen == INT_MAX)
        cout << -1;
    else
        cout << s.substr(start, minLen);
}