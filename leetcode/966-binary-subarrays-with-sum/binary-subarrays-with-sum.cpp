class Solution {
public:
    int cntSub(vector<int>& n, int g) {
        if(g < 0) return 0;
        int l = 0;
        int r = 0;
        int sum = 0;
        int cnt = 0;
        while(r < n.size()) {
            sum += n[r];
            while(sum > g) {
                sum -= n[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int ans = cntSub(nums, goal) - cntSub(nums, goal-1);
        return ans;
    }
};