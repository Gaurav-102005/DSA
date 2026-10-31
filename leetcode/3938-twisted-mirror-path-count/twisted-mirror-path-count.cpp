class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int MOD = 1'000'000'007;

        vector<int> fromAbove(n, 0);
        fromAbove[0] = 1;

        for (int i = 0; i < m; i++) {
            int fromLeft = 0;

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    swap(fromLeft, fromAbove[j]);
                } 
                else {
                    int total = (fromLeft + fromAbove[j]) % MOD;

                    fromLeft = total;
                    fromAbove[j] = total;
                }
            }
        }

        return fromAbove[n - 1];
    }
};