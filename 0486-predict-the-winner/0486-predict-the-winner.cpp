class Solution {
public:
    bool solve(vector<int>& nums, int l, int r, int sum1, int sum2, int turn) {
        if (l > r) {
            return sum1 >= sum2;
        }

        if (turn == 0) {
            // p1
            bool left = solve(nums, l + 1, r, sum1 + nums[l], sum2, 1);

            bool right = solve(nums, l, r - 1, sum1 + nums[r], sum2, 1);

            return left || right;
        } else {
            // p2
            bool left = solve(nums, l + 1, r, sum1, sum2 + nums[l], 0);

            bool right = solve(nums, l, r - 1, sum1, sum2 + nums[r], 0);
            return left && right;
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        return solve(nums, 0, n - 1, 0, 0, 0);
    }
};