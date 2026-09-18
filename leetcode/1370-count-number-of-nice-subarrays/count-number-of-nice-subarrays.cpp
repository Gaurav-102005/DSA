class Solution {
public:
    int cntSub(vector<int>& n, int g) {
        if(g < 0) return 0;
        int l = 0;
        int r = 0;
        int odd = 0;
        int cnt = 0;
        while(r < n.size()) {
            if(n[r] % 2 != 0) {
                odd++;
            }
            while(odd > g) {
                if(n[l]% 2 != 0) odd--;
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