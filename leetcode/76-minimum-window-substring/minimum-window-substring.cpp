class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int hash[256] = {0};

        int l = 0;
        int r = 0;
        int minLen = 1e9;
        int sIndex = -1;
        int cnt = 0;

        for(int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        while(r < n) {

            if(hash[s[r]] > 0) {
                cnt++;
            }

            hash[s[r]]--;

            while(cnt == m) {

                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sIndex = l;
                }

                hash[s[l]]++;

                if(hash[s[l]] > 0) {
                    cnt--;
                }

                l++;
            }

            r++;
        }

        if(sIndex == -1) {
            return "";
        }

        return s.substr(sIndex, minLen);
    }
};