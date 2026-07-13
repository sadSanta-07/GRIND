class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> res = arr;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;

        int rank = 1;

        for (int x : arr) {
            if (mp.find(x) == mp.end()) {
                mp[x] = rank;
                rank++;
            }
        }

        for (int i = 0; i < res.size(); i++) {
            res[i] = mp.find(res[i])->second;
        }
        return res;
    }
};