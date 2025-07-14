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
### Kadane's Algorithm
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
