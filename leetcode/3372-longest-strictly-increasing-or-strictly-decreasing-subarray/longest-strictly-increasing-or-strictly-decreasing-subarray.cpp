class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            bool inc = true;
            bool dec = true;

            for (int j = i + 1; j < n; j++) {

                if (nums[j] > nums[j - 1]) {
                    dec = false;
                }
                else if (nums[j] < nums[j - 1]) {
                    inc = false;
                }
                else {
                    break;
                }

                if (!inc && !dec) {
                    break;
                }

                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};