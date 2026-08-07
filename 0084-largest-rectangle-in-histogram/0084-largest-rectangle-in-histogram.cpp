class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        vector<int>right(n, n);
        vector<int>left(n, -1);
        //right smaller
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        //left smaller
        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
            left[i]=st.top();
            }
            st.push(i);
        }
        int maxArea = 0;
        for(int i = 0; i<n; i++){
            int w = right[i]-left[i]-1;
            int curr = w*heights[i];
            maxArea = max(maxArea, curr);
        }
        return maxArea;
    }
};