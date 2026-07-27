class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefsum = 0;
        int cnt = 0;
        unordered_map<int, int> mp;
        mp[0]++;
        for (int i = 0; i < nums.size(); i++) {
            prefsum += nums[i];

            if (mp.find(prefsum - k) != mp.end()) {
                cnt += mp[prefsum - k];
            }
            mp[prefsum]++;
        }
        return cnt;
    }
};