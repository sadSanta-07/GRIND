class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        for (int i = 0; i < newInterval.size(); i++) {
            intervals.push_back(newInterval);
        }
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        res.push_back(intervals[0]);
        for (int j = 1; j < intervals.size(); j++) {
            if (intervals[j][0] <= res.back()[1]) {
                res.back()[1] = max(res.back()[1], intervals[j][1]);
            } else {
                res.push_back(intervals[j]);
            }
        }
        return res;
    }
};