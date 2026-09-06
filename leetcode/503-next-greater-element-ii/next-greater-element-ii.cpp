class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nge;
        stack<int> st;
        for(int i = 2*nums.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i % nums.size()]) {
                st.pop();
            }

            if(i < nums.size()) {
                int x = st.empty()? -1 : st.top(); 
                nge.push_back(x);
            }
            st.push(nums[i % nums.size()]);
        } 
        reverse(nge.begin(), nge.end());
        return nge;
    }
};