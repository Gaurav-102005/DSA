class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int nse = heights.size();
        int pse = -1;
        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, (heights[element] * (nse-pse-1)));
            }
            st.push(i);
        }
        while(!st.empty()) {
            int element = st.top();
            st.pop();
            nse = heights.size();
            pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (heights[element] * (nse-pse-1)));
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int> heights(m,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1') {
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
            }
            int area = largestRectangleArea(heights);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};