class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = nums[0];
        int j = nums[nums.size() - 1];
        return __gcd(i, j);
    }
};