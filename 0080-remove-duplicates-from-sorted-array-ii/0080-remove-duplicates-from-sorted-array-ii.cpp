class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int i = 0;
        for (int x : nums) {
            if (i < 2 || x != nums[i - 2]) {
                nums[i] = x;
                i++;
            }
        }
        return i;
    }
};