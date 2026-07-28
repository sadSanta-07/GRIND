class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();

        // interval before new
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        // 2 merge overlapping shi
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        res.push_back(newInterval);

        // 3 interval after newInterval

        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;

        // brutw(nlogn)

        // for (int i = 0; i < newInterval.size(); i++) {
        //     intervals.push_back(newInterval);
        // }
        // sort(intervals.begin(), intervals.end());

        // res.push_back(intervals[0]);
        // for (int j = 1; j < intervals.size(); j++) {
        //     if (intervals[j][0] <= res.back()[1]) {
        //         res.back()[1] = max(res.back()[1], intervals[j][1]);
        //     } else {
        //         res.push_back(intervals[j]);
        //     }
        // }
        // return res;
    }
};