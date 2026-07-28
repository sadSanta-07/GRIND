class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        int n = firstList.size();
        int m = secondList.size();

        vector<int> temp(2);

        // fstlist = i = n;
        // secondlst = j = m;

        while (i < n && j < m) {
            if (firstList[i][0] <= secondList[j][1] &&
                secondList[j][0] <= firstList[i][1]) {

                temp[0] = max(firstList[i][0], secondList[j][0]);
                temp[1] = min(firstList[i][1], secondList[j][1]);
                res.push_back(temp);
            }

            if (firstList[i][1] > secondList[j][1])
                j++;
            else
                i++;
        }
        return res;
    }
};