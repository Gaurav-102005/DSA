class Solution {
public:

    unordered_set<string> ans;

    void solve(string& s, int index, int leftRem, int rightRem,
               int balance, string path) {

        if(index == s.size()) {

            if(leftRem == 0 && rightRem == 0 && balance == 0)
                ans.insert(path);

            return;
        }

        char c = s[index];

        if(c == '(') {

            if(leftRem > 0) {
                solve(s, index + 1, leftRem - 1,
                      rightRem, balance, path);
            }

            solve(s, index + 1, leftRem,
                  rightRem, balance + 1, path + c);
        }

        else if(c == ')') {

            if(rightRem > 0) {
                solve(s, index + 1, leftRem,
                      rightRem - 1, balance, path);
            }

            if(balance > 0) {
                solve(s, index + 1, leftRem,
                      rightRem, balance - 1, path + c);
            }
        }

        else {
            solve(s, index + 1, leftRem,
                  rightRem, balance, path + c);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRem = 0;
        int rightRem = 0;

        for(char c : s) {

            if(c == '(') {
                leftRem++;
            }
            else if(c == ')') {

                if(leftRem > 0)
                    leftRem--;
                else
                    rightRem++;
            }
        }

        string path = "";

        solve(s, 0, leftRem, rightRem, 0, path);

        return vector<string>(ans.begin(), ans.end());
    }
};