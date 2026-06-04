#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    static int countVowels(string s){
        int cnt = 0;
        for(char ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' ||ch == 'o' || ch == 'u'){
                cnt++;
            }
        }
        return cnt;
    }
    static bool cmp(string a, string b){
        int va = countVowels(a);
        int vb = countVowels(b);
        if(va != vb){
            return va > vb;
        }
        if(a.length() != b.length()){
            return a.length() < b.length();
        }
        return a < b;
    }

    void leaderboard(vector<string> &arr){
        sort(arr.begin(), arr.end(), cmp);
    }
};

int main()
{
    int n;
    cin >> n;

    vector<string> arr(n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;

    obj.leaderboard(arr);

    for(string s : arr)
    {
        cout << s << endl;
    }

    return 0;
}