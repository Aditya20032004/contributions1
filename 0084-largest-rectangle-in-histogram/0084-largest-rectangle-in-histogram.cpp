class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int> st;
        int maxA=0;
        for (int i=0;i<=n;i++){
            while (!st.empty() && (i==n || h[st.top()]>=h[i])){
                int height=h[st.top()];
                int w;
                st.pop();
                if (st.empty()) w =i;
                else w =i-st.top()-1;
                maxA= max(maxA,w*height);
            }
            st.push(i);
        }              
        return maxA;
    }
};