class Solution {
public:
    // T.C = O(n) S.C = O(1) --> Optimal
    int maxDepth(string s) {
        int x = 0;
        int y = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                x++;
                y = max(y, x);
            }
            else if(s[i] == ')'){
                x--;
            }
        }
        return y;
    }
};