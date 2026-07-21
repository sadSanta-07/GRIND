class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<int> arr;
        int cnt = 0;
        int cntone = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cntone++;
                if (cnt > 0) {
                    arr.push_back(cnt);
                    cnt = 0;
                }
            } else {
                cnt++;
            }
        }
        if (cnt > 0)
            arr.push_back(cnt);
            
        int mx = 0;

        for (int i = 1; i < arr.size(); i++) {
            mx = max(mx, arr[i] + arr[i - 1]);
        }

        return mx + cntone;
    }
};