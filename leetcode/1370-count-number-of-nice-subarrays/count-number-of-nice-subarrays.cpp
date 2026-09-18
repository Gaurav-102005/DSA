class Solution {
public:
    int cntSub(vector<int>& n, int g) {
        if(g < 0) return 0;
        int l = 0;
        int r = 0;
        int sum = 0;
        int cnt = 0;
        while(r < n.size()) {
            sum += n[r]%2;
            while(sum > g) {
                sum -= n[l]%2;
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {

        int ans = cntSub(nums, k) - cntSub(nums, k-1);
        return ans;
    }
};