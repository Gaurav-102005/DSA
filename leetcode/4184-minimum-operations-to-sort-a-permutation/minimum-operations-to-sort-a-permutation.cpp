
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        bool ascending = true;
        bool descending = true;

        for (int i = 1; i < n; i++) {
            if (nums[i] != (nums[0] + i) % n)
                ascending = false;

            if (nums[i] != (nums[0] - i + n) % n)
                descending = false;
        }

        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();

        if (ascending) {
            return min(zero, n - zero + 2);
        }

        if (descending) {
            int rotateThenReverse = (zero + 1) % n + 1;
            int reverseThenRotate = n - zero;

            return min(rotateThenReverse, reverseThenRotate);
        }

        return -1;
    }
};
