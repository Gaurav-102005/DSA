class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        
        vector<long long> ans(k, 0);
        
        vector<long long> dp(k, 0);

        for(int x : nums) {
            
            vector<long long> newDp(k, 0);

            newDp[x % k]++;

            for(int r = 0; r < k; r++) {
                if(dp[r] > 0) {
                    int newR = (r * (x % k)) % k;
                    newDp[newR] += dp[r];
                }
            }

            for(int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
};