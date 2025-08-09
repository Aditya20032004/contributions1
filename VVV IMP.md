# DAY 26
## Trapping rainwater
### Optimal approach
```cpp
class Solution {
public:
    int trap(vector<int>& h) {
        int l=0,r=h.size()-1;
        int res=0;
        int left_max=0,right_max=0;
        while (l<=r){
            if (h[l]<=h[r]){
                if (h[l]>left_max) left_max = h[l];
                else res+=(left_max-h[l]);
                l++;
            }
            else{
                if (h[r]>right_max) right_max = h[r];
                else res+=(right_max-h[r]);
                r--;
            }
        }      
        return res;
    }
};
```
# DAY 28
## ASTEROID COLLISION
### Optimal Approach
```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        int n= arr.size();
        for (int i=0;i<n;i++){
            if (arr[i]>0) st.push(arr[i]);
            else{
                while (!st.empty() && st.top()<abs(arr[i]) && st.top()>0) st.pop();
                if (!st.empty() && st.top()==abs(arr[i])) st.pop();
                else if (st.empty() || st.top()<0) st.push(arr[i]); 
            }
        }
        vector<int> nums;
        int x;
        while (!st.empty()){
            x=st.top();
            st.pop();
            nums.push_back(x);
        }

        reverse(nums.begin(),nums.end());
        return nums;
    }
};
```


# DAY29
## Sum of subarray ranges ( difference of maximum and smallest ele in a subarray and then sum of all such subaarray )
### Brute force approach
```cpp
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        for (int i=0;i<n;i++){
            int mini=nums[i];
            int maxi=nums[i];
            for (int j=i;j<n;j++){
                maxi =max(nums[j],maxi);
                mini = min(nums[j],mini);
                res +=maxi-mini;
            }
        }      
        return res;  
    }
};
```

### Optimal Approach
```cpp
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<long long> minPrev(n, -1), minNext(n, n);
        vector<long long> maxPrev(n, -1), maxNext(n, n);
        
        // Compute previous and next smaller elements (for minimums)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                minPrev[i] = st.top();
            }
            st.push(i);
        }
        
        st = stack<int>(); // Reset stack for next pass
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                minNext[i] = st.top();
            }
            st.push(i);
        }
        
        st = stack<int>(); // Reset stack for maximums
        // Compute previous and next larger elements (for maximums)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                maxPrev[i] = st.top();
            }
            st.push(i);
        }
        
        st = stack<int>(); // Reset stack for next pass
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                maxNext[i] = st.top();
            }
            st.push(i);
        }
        
        long long sumMin = 0, sumMax = 0;
        for (int i = 0; i < n; i++) {
            sumMin += nums[i] * (i - minPrev[i]) * (minNext[i] - i);
            sumMax += nums[i] * (i - maxPrev[i]) * (maxNext[i] - i);
        }
        
        return sumMax - sumMin;
    }
};
```
