class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        long long n = min(need1, need2);
        long long x = min(cost1 + cost2, costBoth);
        ans = x * n;
        if(need1 > need2) {
            ans += 1LL * min(cost1, costBoth) * (need1 - need2);
        }
        else{
            ans += 1LL * min(cost2, costBoth) * (need2 - need1);
        }
        return ans;
    }
};