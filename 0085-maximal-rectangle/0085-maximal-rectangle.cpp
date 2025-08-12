class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> psum(row, vector<int>(col, 0)); 
        int maxA= 0;
        for (int i=0; i<col;i++){
            int sum =0;
            for (int j =0;j<row;j++){
                if (mat[j][i]=='1') sum +=1;
                else sum=0;
                psum[j][i]=sum;
            }
        }        
        for (int i=0;i<row;i++){
            maxA = max(maxA, largestHist(psum[i]));
        }
        return maxA;
    }
    int largestHist(vector<int>& arr){
        stack<int> st;
        int n= arr.size();
        int maxi =0;
        for (int i=0;i<=arr.size();i++){
            while (!st.empty() && (i==n || arr[st.top()]>arr[i])){
                int h =arr[st.top()];
                int w;
                st.pop();
                if (st.empty()) w = i;
                else w = i-st.top()-1;
                maxi = max(maxi, w*h);
            }
            st.push(i);
        }
        return maxi;
    }
};