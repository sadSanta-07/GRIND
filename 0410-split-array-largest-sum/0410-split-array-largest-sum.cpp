class Solution {
public:
    bool isValid(vector<int>& nums, int k, int mid) {

        int subarrays = 1;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mid) {
                return false;
            }

            if (sum + nums[i] <= mid) {
                sum += nums[i];
            } else {
                subarrays++;
                sum = nums[i];
            }
        }

        return subarrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        int left = 0;
        int right = accumulate(nums.begin(), nums.end(), 0);

        int ans = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (isValid(nums, k, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};