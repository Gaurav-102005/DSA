class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = nums[0];
        int prev2 = 0;
        for(int i = 0; i<nums.size(); i++) {
            int take = nums[i];
            if(i > 1) take += prev2;
            int notTake = 0 + prev1;
            int cur = max(take, notTake);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};