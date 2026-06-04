#include <iostream>
#include <string>
using namespace std;
int start = 0;
int maxl = 1;
void expand(string &s, int left, int right){
    while(left >= 0 && right < s.length() && s[left] == s[right]){
        int currl = right - left + 1;

        if(currl > maxl){
            maxl = currl;
            start = left;
        }
        left--;
        right++;
    }
}
int main(){
    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++){
        expand(s, i, i);
        expand(s, i, i + 1);
    }
    cout << s.substr(start, maxl);
    return 0;
}