#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countAboveAvg(vector<int>& score)
    {
        int sum = 0;
        for (int x : score)
        {
            sum += x;
        }
        int avg = sum / score.size();
        int count = 0;

        for (int x : score)
        {
            if (x > avg)
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;

    vector<int> score = {40, 80, 60, 90, 50};

    cout << s.countAboveAvg(score);

    return 0;
}