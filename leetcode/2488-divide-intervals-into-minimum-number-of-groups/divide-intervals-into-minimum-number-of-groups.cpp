class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> s(n);
        vector<int> e(n);
        for(int i = 0; i < n; i++) {
            s[i] = intervals[i][0];
            e[i] = intervals[i][1];
        }

        sort(s.begin(), s.end());
        sort(e.begin(), e.end());

        int i = 0;
        int j = 0;
        int g = 0;
        int mg = 0;
        while(i < n && j < n) {
            if(s[i] <= e[j]) {
                g++;
                i++;
            }
            else {
                g--;
                j++;
            }
            mg = max(mg, g);
        }
        return mg;
    }
};