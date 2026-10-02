class Solution {
public:
    void solve(int n, int o, int c, string &curr, vector<string> &ans){
        if(curr.length() == 2*n){
            ans.push_back(curr);
            return;
        }
        if(o < n){
            curr.push_back('(');
            solve(n, o+1, c, curr, ans);
            curr.pop_back();
        }
        if(c < o){
            curr.push_back(')');
            solve(n, o, c+1, curr, ans);
            curr.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        solve(n, 0, 0, curr, ans);
        return ans;
    }
};