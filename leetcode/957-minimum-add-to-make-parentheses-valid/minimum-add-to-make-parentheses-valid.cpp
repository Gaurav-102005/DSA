class Solution {
public:
    int minAddToMakeValid(string s) {
        int b = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(b < 0 && s[i] == '(') {
                ans = ans + abs(b);
                b = 1;
            }
            else{
                if(s[i] == '('){
                    b++;
                }
                else{
                    b--;
                }
            }
        }
        if(!s.empty()) ans = ans + abs(b);
        return ans;
    }
};
