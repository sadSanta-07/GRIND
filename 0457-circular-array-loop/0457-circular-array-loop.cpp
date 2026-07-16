class Solution {
public:
    int calcNextIdx(vector<int>& nums, int curr) {
        int n = nums.size();
        return ((curr + nums[curr]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        // seq, k > 1 all positives or all negatives
        // check for all indexes
        for (int i = 0; i < nums.size(); i++) {
            // set => indexes which we have visited so far
            // flag -> isPos = nums[i] > 0
            // [2, -2, -1, 2, 2]
            //  0
            unordered_set<int> st;
            st.insert(i);

            bool isPos = nums[i] > 0;
            int curr = i;

            // cycle detection
            while (true) {
                int next = calcNextIdx(nums, curr);

                if (isPos) {
                    if (nums[next] < 0) {
                        break;
                    } else {
                        if (st.count(next)) {
                            // cycle is there
                            // k > 1

                            if (curr != next) {
                                return true;
                            } else {
                                break;
                            }
                        }
                        st.insert(next);
                    }

                } else {
                    if (nums[next] > 0) {
                        break;
                    } else {
                        if (st.count(next)) {
                            // cycle is there
                            // k > 1
                            if (curr != next) {
                                return true;
                            } else {
                                break;
                            }
                        }
                        st.insert(next);
                    }
                }

                curr = next;
            }
        }

        return false;
    }
};