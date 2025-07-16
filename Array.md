# Day4
 ## 2sum problem
 ```cpp
    class Solution {
      public:
          vector<int> twoSum(vector<int>& arr,int target){
              unordered_map<int,int> mpp;
              for (int i =0;i<arr.size();i++){
                  int more = target-arr[i];
                  if (mpp.find(more) != mpp.end()){
                      return {mpp[more],i};
                  }
                  mpp[arr[i]] = i;
              }
              return {-1,-1};
          }
      };
```
## Sort an array of 0s, 1s and 2s
### Better Approach
```cpp
    class Solution {
      public:
        void mergeSort(vector<int> &arr, int l, int r) {
            // code here
            if (l>=r) return;
            int mid = (l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
        void merge(vector<int> &arr,int l,int mid,int r){
            vector<int> temp;
            int left = l ;
            int right = mid+1;
            while (left<=mid && right<=r){
                if (arr[left]<=arr[right]){
                    temp.push_back(arr[left]);
                    left++;
                }
                else{
                    temp.push_back(arr[right]);
                    right++;
                }
            }
            while (left<=mid){
                temp.push_back(arr[left]);
                left++;
            }
            while (right<=r){
                temp.push_back(arr[right]);
                right++;
            }
            for (int i = l;i<=r;i++){
                arr[i]= temp[i-l];
            }
        }
        void ms(vector<int> &arr,int n){
            mergeSort(arr,0,n-1);
        }
    };
 ```
### Optimal Approach( Dutch National Flag Algorithm )
```cpp
    class Solution {
      public:
          void sortColors(vector<int>& arr) {
              int low,mid=0;  
              int high = arr.size()-1;
              while (mid<=high){
                  if (arr[mid]==0){
                      swap(arr[low],arr[mid]);
                      low++;
                      mid++;
                  }
                  else if (arr[mid]==1){
                      mid++;
                  }
                  else{
                      swap(arr[mid],arr[high]);
                      high--;
                  }
              }    
          }
      };
```

# Day 5
## Majority element occuring more than n/2
### Using Hashing (map)(Better Approach)

```cpp

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mpp;
        for (int i =0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for (auto it:mpp){
            if (it.second>(nums.size()/2)){
                return (it.first);
            }
        }
        return -1;        
    }
};
```

### Optimal Approach Moore'S voting algoritm
  ```cpp
    class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int el;
            int count = 0;
            for (int i=0; i<nums.size();i++){
                if (count == 0){
                    el = nums[i];
                    count = 1;
                }
                else if (nums[i]==el) count++;
                else count--;
            }
            int x = 0;
            for (int j=0;j<nums.size();j++){
                if (nums[j]==el) x++;
            }
            if (x>nums.size()/2){
                return el;
            }
            else return -1;  
        }      
    };
```
### Boyer-Moore's voting algorithm( 2 majority elements)
```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1;
        int c1 =0;
        int el2;
        int c2=0;
        vector<int> arr;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==el1) c1++;
            else if (c2==0 && el1!=nums[i]){
                el2=nums[i];
                c2=1;
            }
            else if (c1==0 && el2!=nums[i]){
                el1 = nums[i];
                c1 = 1;
            } 
            else if (nums[i]==el2) c2++;
            else c1--,c2--; 
        }
        c1=0;
        c2=0;
        for (int j =0;j<nums.size();j++){
            if (nums[j]==el1) c1++;
            else if (nums[j]==el2) c2++;
        }        
        if (c1>nums.size()/3){
            arr.push_back(el1);
        }
        if (c2>nums.size()/3){
            arr.push_back(el2);
        }
        return arr;
    }
};
```


# DAY 6
## Maximum subarray sum
### Better approach or a brute force approach
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        for (int i=0;i<nums.size();i++){
            int sum = 0;
            for (int j =i;j<nums.size();j++){
                sum +=nums[j];
                maxi = max(maxi,sum);
            }
        }
        return maxi;        
    }
};
```
### Kadane's Algorithm(variant 1)
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        for (int i = 0; i<nums.size();i++){
            sum +=nums[i];
            if (sum>maxi){
                maxi =  sum;
            }
            if (sum<0){
                sum = 0;
            }
        }
        return maxi;        
    }
};
```
### Kadane's Algorithm(variant 2)
```cpp
// C++ Program to print subarray with maximum sum using nested loops 

#include <bits/stdc++.h>
using namespace std;

// Function to find the subarray with maximum sum
vector<int> maxSumSubarray(vector<int> &arr) {
    
    // start and end of max sum subarray
    int resStart = 0, resEnd = 0;
  
    // Initialize the maximum subarray sum with the first element
    int maxSum = arr[0];

    for (int i = 0; i < arr.size(); i++) {
        
        // Initialize current subarray sum with 0
        int currSum = 0;
        for(int j = i; j < arr.size(); j++) {
            currSum += arr[j];
            
            // If current subarray has greater sum than maximum sum subarray,
            // then update the start and end of maximum sum subarray
            if(currSum > maxSum) {
                maxSum = currSum;
                resStart = i;
              	resEnd = j;
            }
        }
    }
  
    vector<int> res;
    for(int i = resStart; i <= resEnd; i++)
        res.push_back(arr[i]);
    return res;
}

int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    vector<int> res = maxSumSubarray(arr);
  
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
  
    return 0;
}
```

## STOCK(BUY & SELL)
### Brute force
```cpp
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int maxi = 0;
        for (int i =0;i<nums.size();i++){
            for(int j =i+1;j<nums.size();j++){
                if (nums[i]<nums[j]){
                    maxi = max(nums[j]-nums[i],maxi);
                }
            }
        }
        return maxi;     
    }
};
```
### Optimal Approach
```cpp
class Solution {
public:
    int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int minPrice = INT_MAX;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i]<minPrice){
            minPrice = arr[i];
        }
        if (maxPro < (arr[i]-minPrice)){
            maxPro = arr[i]-minPrice;
        }
    }
    return maxPro;
}
};
```
# Day 7
## Rearrange array elements by sign
### Optimal Approach(  Equal number of pos and neg )
```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> arr(nums.size(),0);
        int neg=1,pos=0;
        for (int i =0;i<nums.size();i++){
            if (nums[i]>0){
                arr[pos]=nums[i];
            }
            else {
                arr[neg]=nums[i];
                neg +=2;
            }
        }
        return arr;
    }
};
```

## Next Permuatation
```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};
```
# Day 8
## Leaders in an array(elements in greater than all elements on its right)
```cpp
vector<int> printLeaders(int arr[], int n) {

  vector<int> ans;
  
 // Last element of an array is always a leader,
 // push into ans array.
 int max = arr[n - 1];
 ans.push_back(arr[n-1]);

  // Start checking from the end whether a number is greater
  // than max no. from right, hence leader.
  for (int i = n - 2; i >= 0; i--)
    if (arr[i] > max) {
      ans.push_back(arr[i]);
      max = arr[i];
    }

  
  return ans;
}
```

## longest consecutive sequence in an array
### Better approach
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest =1, count=0;
        int last_smaller = INT_MIN;
        sort(nums.begin(),nums.end());
        if (nums.size()==0) return 0;
        for (int i =0; i<nums.size();i++){
            if (nums[i]-1==last_smaller){
                count +=1;
            }
            else if (nums[i]!=last_smaller){
                count = 1;
            } 
            last_smaller = nums[i];
            longest = max(longest,count);
        }
        return longest;        
    }
    
};
```
### optimal approach
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int longest = 0; // Initialize to 0 to handle empty input
        if (nums.size() == 0) return 0;
        for (int num : nums) {
            st.insert(num);
        }
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int count = 1;
                int x = it;
                while (st.find(x + 1) != st.end()) {
                    count += 1;
                    x = x + 1;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};
```
