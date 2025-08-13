# Day 30
## Sliding window maximum 
### Brute force approach
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        vector<int> arr;
        if (k==1) return nums;
        for (int i=0;i<=nums.size()-k;i++){
            for (int j=i;j<=i+k-1;j++){
                maxi = max(nums[j],maxi);   
            }
            arr.push_back(maxi);
        }   
        return arr;
    }
};
```
### OPtimal Approach
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> dq;
        vector<int> maxi;
        for (int i=0;i<nums.size();i++){
            if (!dq.empty() && dq.front()==i-k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);

            if (i>=k-1) maxi.push_back(nums[dq.front()]); 
        }        
        return maxi;
    }
};
```
