class Solution {
public:
    vector<int> findNSE(vector<int>& arr) {
        vector<int> nse;
        stack<int> st;
        for(int i = arr.size()-1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            int x = st.empty() ? arr.size() : st.top();
            nse.push_back(x);
            st.push(i);
        }
        reverse(nse.begin(), nse.end());
        return nse;
    }

    vector<int> findPSE(vector<int>& arr) {
        vector<int> pse;
        stack<int> st;
        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            int x = st.empty() ? -1 : st.top();
            pse.push_back(x);
            st.push(i);
        }
        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        int mod = (int)(1e9 + 7);
        int total = 0;
        for(int i = 0; i < arr.size(); i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            total = (total + (right * left * (1LL) * arr[i]) % mod) % mod;
        } 
        return total;
    }
};