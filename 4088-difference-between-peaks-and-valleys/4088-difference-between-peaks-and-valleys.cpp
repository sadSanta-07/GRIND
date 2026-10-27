class Solution {
public:
    long long peakValleyDifference(vector<int>& nums) {
        int n = nums.size();
        long long peak = 0 ,valley = 0;
        if (n < 3) {
            return 0;
        }
        for (int i = 1; i < n - 1; i++) {
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
                peak += nums[i];
            }
            if (nums[i - 1] > nums[i] && nums[i] < nums[i + 1]) {
                valley += nums[i];
            }
        }
        return peak - valley;
    }
};