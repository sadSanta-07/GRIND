#include <iostream>
#include <unordered_map>
using namespace std;

void pangram(string s)
{
    unordered_map<char,int> mp;
    for (char ch : s)
    {
        mp[ch]++;
    }
    for (char c = 'A'; c <= 'Z'; c++)
    {
        if (mp.find(c) == mp.end() && mp.find(c - 'A' + 'a') == mp.end())
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main()
{

    int n;
    string s;
    cin >> n >> s;
    pangram(s);
}