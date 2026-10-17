class Solution {
public:
    // int f(int n, vector<int>& dp) {
    //     if(n == 0 || n ==  1) return 1;
    //     if(dp[n] != -1) return dp[n];
    //     int left = f(n-1, dp);
    //     int right = f(n-2, dp);
    //     return dp[n] = left + right;
    // }
    int climbStairs(int n) {
        if(n <= 2) return n;
        int prev2 = 1;
        int prev1 = 2;

        for(int i = 3; i<=n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};