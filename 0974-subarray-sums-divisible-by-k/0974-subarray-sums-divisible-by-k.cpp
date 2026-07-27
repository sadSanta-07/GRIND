// s1 % k =
// x s2 % k = x s1 =
// k* n + x s2 =
// k* m + x subarraySum =
// s2 - s1 =
// k *
//(m - n) Which proves that the subarray is divisible by k

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int sum = 0;

        mp[0] = 1;

        int result = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int rem = sum % k;

            if (rem < 0) {
                rem += k;
            }

            if (mp.find(rem) != mp.end()) {
                result += mp[rem];
            }

            mp[rem]++;
        }

        return result;
    }
};