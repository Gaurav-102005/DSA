class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long budget = 1LL * k1 + k2;
        int n = nums1.size();

        vector<long long> diff(n);
        long long maxDiff = 0, sumDiff = 0;

        for(int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            sumDiff += diff[i];
        }

        if(budget >= sumDiff) return 0;

        long long low = 0, high = maxDiff;

        while(low < high) {
            long long mid = low + (high - low) / 2;
            long long needed = 0;

            for(long long d : diff) {
                if(d > mid) needed += d - mid;
            }

            if(needed > budget) low = mid + 1;
            else high = mid;
        }

        long long remaining = budget;
        long long ans = 0;

        for(long long& d : diff) {
            if(d > low) {
                remaining -= d - low;
                d = low;
            }
            ans += d * d;
        }

        for(long long& d : diff) {
            if(remaining > 0 && d == low && d > 0) {
                ans -= d * d;
                d--;
                ans += d * d;
                remaining--;
            }
        }

        return ans;
    }
};