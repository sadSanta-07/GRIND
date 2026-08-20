class Solution {
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int maxreach = startFuel;
        int count = 0;
        int index = 0;

        while (maxreach < target) {
            while (index < stations.size() && stations[index][0] <= maxreach) {
                pq.push(stations[index][1]);
                index++;
            }
            if (pq.empty())
                return -1;
            maxreach += pq.top();
            pq.pop();
            count++;
        }

        return count;
    }
};