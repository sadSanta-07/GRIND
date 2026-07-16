class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = INT_MIN;
        vector<int> prefixGcd;
        for (int i = 0; i < nums.size(); i++) {
            mx = max(nums[i], mx);
            prefixGcd.push_back(__gcd(nums[i], mx));
        }
        sort(prefixGcd.begin(), prefixGcd.end());

        int i = 0;
        int j = prefixGcd.size() - 1;

        long long sum = 0;

        while (i < j) {
            sum += __gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }

        return sum;
    }
};