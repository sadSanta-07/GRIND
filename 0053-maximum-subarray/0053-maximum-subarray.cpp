class Solution {
public:
    int crossSum(vector<int>& nums, int l, int mid, int r) {

        int leftSum = INT_MIN;
        int sum = 0;

        for (int i = mid; i >= l; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        int rightSum = INT_MIN;
        sum = 0;

        for (int i = mid + 1; i <= r; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }

        return leftSum + rightSum;
    }

    int solve(vector<int>& nums, int l, int r) {

        if (l == r)
            return nums[l];

        int mid = (l + r) / 2;

        int left = solve(nums, l, mid);
        int right = solve(nums, mid + 1, r);
        int cross = crossSum(nums, l, mid, r);

        return max({left, right, cross});
    }

    int maxSubArray(vector<int>& nums) {

        return solve(nums, 0, nums.size() - 1);
    }
};