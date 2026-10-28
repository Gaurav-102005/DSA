
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int X = 1024;

        vector<bitset<X>> dp(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];

                if (i == 0 && j == 0) {
                    dp[j].reset();
                    dp[j].set(val);
                    continue;
                }

                bitset<X> top = dp[j];
                bitset<X> left;

                if (j > 0) {
                    left = dp[j - 1];
                }

                bitset<X> curr;

                for (int x = 0; x < X; x++) {
                    if (top[x]) {
                        curr.set(x ^ val);
                    }
                    if (left[x]) {
                        curr.set(x ^ val);
                    }
                }

                dp[j] = curr;
            }
        }

        for (int x = 0; x < X; x++) {
            if (dp[n - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};
