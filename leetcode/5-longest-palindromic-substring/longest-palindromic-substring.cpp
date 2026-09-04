class Solution {
public:
    // T.C = O(n) S.C = O(1) --> Optimal
    string longestPalindrome(string s) {
        string t = "#";
        for(char c : s){
            t += c;
            t += '#';
        }

        int n = t.size();
        vector<int> p(n, 0);

        int center = 0, right = 0;
        int maxLen = 0, start = 0;

        for(int i = 0; i < n; i++){
            int mirror = 2 * center - i;

            if(i < right)
                p[i] = min(right - i, p[mirror]);

            int l = i - (p[i] + 1);
            int r = i + (p[i] + 1);

            while(l >= 0 && r < n && t[l] == t[r]){
                p[i]++;
                l--; r++;
            }

            if(i + p[i] > right){
                center = i;
                right = i + p[i];
            }

            if(p[i] > maxLen){
                maxLen = p[i];
                start = (i - maxLen) / 2;
            }
        }

        return s.substr(start, maxLen);
    }

    // T.C = O(n*n) S.C = O(1) --> Better
    // string expand(string &s, int l, int r){
    //     while(l >= 0 && r < s.size() && s[l] == s[r]){
    //         l--, r++;
    //     }
    //     return s.substr(l+1, r-l-1);
    // }
    // string longestPalindrome(string s) {
    //     string ans = "";

    //     for(int i = 0; i<s.size(); i++){
    //         string odd = expand(s, i, i);
    //         string even = expand(s, i, i+1);

    //         if(odd.size() > ans.size()) ans = odd;
    //         if(even.size() > ans.size()) ans = even;
    //     }
    //     return ans;
    // }

    // T.C = O(n*n*n) S.C = O(1) --> Brute Force
    // bool isPalindrome(string &s, int l, int r){
    //     while(l < r){
    //         if(s[l] != s[r]) return false;
    //         l++; r--;
    //     }
    //     return true;
    // }

    // string longestPalindrome(string s) {
    //     int n = s.size();
    //     string ans = "";

    //     for(int i = 0; i<n; i++){
    //         for(int j = i; j<n; j++){
    //             if(isPalindrome(s, i, j)){
    //                 if(j-i+1 > ans.size()){
    //                     ans = s.substr(i, j-i+1);
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }
};