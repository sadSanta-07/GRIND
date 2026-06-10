#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int prembadge(string s1, string s2)
    {
        int count = 0;
        unordered_map<char, int> tmp;
        for (int i = 0; i < s1.size(); i++)
        {
            tmp[s1[i]]++;
        }

        for (int i = 0; i < s2.size(); i++)
        {
            if (tmp[s2[i]] > 0){
                count++;
            }
        }
        return count;
    }
};

int main()
{
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);

    Solution obj;
    cout << obj.prembadge(s1,s2);

    return 0;
}