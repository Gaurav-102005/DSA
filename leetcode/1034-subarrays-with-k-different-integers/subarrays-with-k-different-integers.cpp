class Solution {
public:
    int cntSub(vector<int>& n, int k) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        map<int, int> mpp;
        while(r < n.size()) {
            mpp[n[r]]++;
            while(mpp.size() > k) {
                mpp[n[l]]--;
                if(mpp[n[l]] == 0) mpp.erase(n[l]);
                l++;
            }
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = cntSub(nums, k) - cntSub(nums, k-1);
        return ans;
    }
};