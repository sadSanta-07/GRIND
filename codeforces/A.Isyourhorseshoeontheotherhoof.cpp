#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> uniqueValues;
    int x, w, y, z;
    cin >> w >> x >> y >> z;

    uniqueValues.insert(w);
    uniqueValues.insert(x);
    uniqueValues.insert(y);
    uniqueValues.insert(z);

    cout << 4 - uniqueValues.size() << '\n';

}
