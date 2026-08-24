class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        multiset<int> small, large;

        auto add = [&](int x) {
            if (small.empty() || x <= *small.rbegin())
                small.insert(x);
            else
                large.insert(x);

            if (small.size() > large.size() + 1) {
                auto it = prev(small.end());
                large.insert(*it);
                small.erase(it);
            }

            if (large.size() > small.size()) {
                auto it = large.begin();
                small.insert(*it);
                large.erase(it);
            }
        };

        auto remove = [&](int x) {
            auto it = small.find(x);

            if (it != small.end()) {
                small.erase(it);
            } else {
                it = large.find(x);
                large.erase(it);
            }

            if (small.size() > large.size() + 1) {
                auto it2 = prev(small.end());
                large.insert(*it2);
                small.erase(it2);
            }

            if (large.size() > small.size()) {
                auto it2 = large.begin();
                small.insert(*it2);
                large.erase(it2);
            }
        };

        for (int i = 0; i < k; i++) {
            add(nums[i]);
        }

        vector<double> res;

        auto getMedian = [&]() -> double {
            if (k % 2 == 1) {
                return *small.rbegin();
            }

            return ((double)*small.rbegin() + (double)*large.begin()) / 2.0;
        };

        res.push_back(getMedian());

        for (int i = k; i < nums.size(); i++) {

            remove(nums[i - k]);

            add(nums[i]);

            res.push_back(getMedian());
        }

        return res;
    }
};