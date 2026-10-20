
class Solution {
public:
    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;
            int prevMax = INT_MIN;

            for (int start = 0; start < n; start += k) {
                int mn = INT_MAX;
                int mx = INT_MIN;
                int descents = 0;

                for (int j = 0; j < k; j++) {
                    int cur = nums[start + j];
                    int nxt = nums[start + (j + 1) % k];

                    if (cur > nxt) descents++;

                    mn = min(mn, cur);
                    mx = max(mx, cur);
                }

                // The block must be sortable by cyclic rotation.
                if (descents > 1) {
                    valid = false;
                    break;
                }

                // Sorted blocks must join in non-decreasing order.
                if (start > 0 && prevMax > mn) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid) ans += k;
        }

        return ans;
    }
};
