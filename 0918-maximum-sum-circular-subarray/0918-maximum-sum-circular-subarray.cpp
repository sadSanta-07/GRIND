class Solution {
public:
    int kadanesMax(vector<int>& nums, int n) {
        int sum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < n; i++) {
            sum = max(sum + nums[i], nums[i]);
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }

    int kadanesMin(vector<int>& nums, int n) {
        int sum = nums[0];
        int minSum = nums[0];

        for (int i = 1; i < n; i++) {
            sum = min(sum + nums[i], nums[i]);
            minSum = min(minSum, sum);
        }

        return minSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        // 1
        int SUM = accumulate(begin(nums), end(nums), 0);

        // 2
        int minsum = kadanesMin(nums, n);

        // 3
        int maxsum = kadanesMax(nums, n); // cs1

        // 4
        int circsum = SUM - minsum;

        if (maxsum > 0) {
            return max(maxsum, circsum);
        }
        return maxsum;
    }
};