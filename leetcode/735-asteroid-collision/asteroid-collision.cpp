class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        st.push(asteroids[0]);
        for(int i = 1; i < asteroids.size(); i++) {
            int x = abs(asteroids[i]);
            if(!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                while(!st.empty() && st.top() > 0 && st.top() < x){
                    st.pop();
                }
                if(st.empty()){
                    st.push(asteroids[i]);
                }
                else if(st.top() < 0) {
                    st.push(asteroids[i]);
                }
                else if(st.top() == x) {
                    st.pop();
                }
            }
            else{
                st.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
