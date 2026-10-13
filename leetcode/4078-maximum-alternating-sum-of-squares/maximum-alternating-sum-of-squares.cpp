class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int& x : nums) {
            x = abs(x);
        }

        sort(nums.begin(), nums.end());

        long long sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            long long square = 1LL * nums[i] * nums[i];

            if(i < n / 2) {
                sum -= square;
            } else {
                sum += square;
            }
        }

        return sum;
    }
};