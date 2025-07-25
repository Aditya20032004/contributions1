# Day 11
## Binary Search ( log (n) )
### Interative approcah
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int m= nums.size();
        int low =0;
        int high =m-1;
        while (low<=high){
            int mid = (low+high)/2;
            if (nums[mid]>target) high = mid -1;
            else if (nums[mid]==target) return mid;
            else low = mid+1;
        }
        return -1;
    }
};
```
### Recursive approach
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low =0;
        int m = nums.size();
        int high =m-1;
        int n = binary_search(nums,low,high,target);
        return n;
    }
    int binary_search(vector<int>& nums,int low,int high, int target){
        if (low>high) return -1;
        int mid = (low+high)/2;
        if (nums[mid]>target) {
            high = mid -1;
            return binary_search(nums,low,high,target);
        }
        else if (nums[mid]==target) return mid;
        else {
            low = mid+1;
            return binary_search(nums,low,high,target);
        }
        return -1;
    }


};
```

## Search insert position
```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0, high=n-1;
        int ans;
        while (low<=high){
            int mid = (low+high)/2;
            if (nums[mid]>=target){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }        
    return ans;
    }
};
```

# DAY 12
## First last occurence of element in an array( log(n) )
### Brute force approach
```
start from back of an array and search for last.
start from front in an array for first occurence.
```
### Optimal approach
```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {        
       int n = nums.size();
       int a = searchfirst(nums,target,n);
       int b = searchlast(nums,target,n);
       vector<int> arr;
       arr.push_back(a);
       arr.push_back(b);
       return arr;
    }

    int searchfirst(vector<int>& nums,int target,int n){
        int low= 0, high = n-1;
        int ans=-1;
        while (low<=high){
            int mid = (low+high)/2;
            if (nums[mid]==target){
                high = mid-1;
                ans = mid;
            }
            else if (nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
    int searchlast(vector<int>& nums,int target,int n){
        int low= 0, high = n-1;
        int ans=-1;
        while (low<=high){
            int mid = (low+high)/2;
            if (nums[mid]==target){
                low = mid+1;
                ans = mid;
            }
            else if (nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};
```
### Find Occurrences of an Element in an Array (O(n))
```cpp
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> arr;
        map<int,int> mpp;
        int n = nums.size();
        int m = queries.size();
        int count = 0;
        for (int i=0; i<n;i++){
            if (nums[i]==x){
                count ++;
                mpp[count]=i;
            }
        }        
        for (int i=0;i<m;i++){
            if (mpp.find(queries[i])!=mpp.end()){
                arr.push_back(mpp[queries[i]]);
            }
            else arr.push_back(-1);
        }
        return arr;
    }
};
```
# Day 13
## search-in-rotated-sorted-array I
### Optimal Approach
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0, high = n-1;
        int ans;
        while (low<=high){
            int mid = (low+high)/2;
            if (nums[mid]== target){
                return mid;
            }
            else if (nums[low]<=nums[mid]){
                if (target >= nums[low] && target<=nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{
                if (target<=nums[high] && target >= nums[mid]) {
                    low = mid+1;
                }
                else high = mid-1;
            }

        }    
        return -1;    
    }
};
```
## search-in-rotated-sorted-array II
### Optimal Approach
```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0, high = n-1;
        int ans;
        while (low<=high){
            int mid = (low+high)/2;
            if (nums[mid]== target){
                return true;
            }
            if (nums[low]== nums[mid] && nums[mid]==nums[high]){
                low++;
                high--;
            }
            else if (nums[low]<=nums[mid]){
                if (target >= nums[low] && target<=nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{
                if (target<=nums[high] && target >= nums[mid]) {
                    low = mid+1;
                }
                else high = mid-1;
            }

        }    
        return false;    
    }
};   
```

# Day 14
## Minimum in Rotated Sorted Array 
### Optimal Approach
```cpp
#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}

```

# DAY 15
## how many an array has been rotated or minimum in a rotated sorted array 
### Brute force (O( n ))
```cpp
class Solution {
public:
    int findMin(vector<int>& arr) {
        int ans = INT_MAX,index = -1;
        for(int i=0;i<arr.size();i++){
            if (arr[i]<ans){
                ans = arr[i];
                index = i;
            }
        }
        return ans; //return index; 

    }
};
```
### Optimal Approach
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int ans = INT_MAX;
        int index = -1;
        int low =0, high = n-1;
        while (low<=high){
            int mid = (low+high)/2;
            if (nums[low]<=nums[high]){
                if (nums[low]<ans){
                    ans = nums[low];
                    index =low;
                }
                break;
            }
            if (nums[low]<=nums[mid]){
                if (nums[low]<ans){
                    ans = nums[low];
                    index = low;
                }
                low = mid+1;

            }
            else {
                if (nums[mid]<ans){
                    ans = nums[mid];
                    index = mid;
                }
                high = mid-1;
            }
        }
        return ans;    
    }
};
```

# DAY 16
## minimum elemnt in an sorted array
### Brute force approach
```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        for (int i=0;i<n;i++){
            if (i==0){
                if (nums[i]!=nums[i+1]) return nums[i];
            }
            else if (i==n-1){
                if (nums[i]!=nums[i-1]) return nums[i];
            }
            else {
                if (nums[i]!=nums[i-1] && nums[i]!=nums[i+1]) return nums[i];
            }
        }
        return -1;    
    }
};
```

### Better approach
```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        for (int i=0;i<n-1;i+=2){
            if (nums[i]!=nums[i+1]){
                return nums[i];
            }
        }
        return nums[n-1];
            
    }
};
```
### Optimal Approach( log( n ) ) 
```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low =1;
        int n =nums.size();
        int high = n-2;
        if (n ==1) return nums[0];
        if (nums[0]!=nums[1]) return nums[0];
        if (nums[n-1]!= nums[n-2]) return nums[n-1];
        while (low<=high){
            int mid = (low+high)/2;
            if (nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            if ((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])){
                low = mid+1;
            }
            else high = mid-1;
        }
        return -1;        
    }
};
```

## Find peak in a sorted array
### optimal Approach
```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low =1;
        int n =nums.size();
        int high =n-2;
        int ans = INT_MIN;
        int index;
        if (n==1) return 0;
        if (nums[n-1]>nums[n-2]) return n-1;
        if (nums[0]>nums[1]) return 0;
        while (low<=high){
            int mid = (low+high)/2;
            if (nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                if (ans<nums[mid]){
                    return mid;
                }
            }
            else if (nums[mid]>nums[mid-1]){
                low = mid+1;
            }
            else high = mid-1;
        }
        return -1;
    }
};
```
# Day 17
## nth root of no. using Binary search
### Optimal Approcah
```cpp
class Solution {
  public:
    int nthRoot(int n, int m) {
        int low = 0;
        int high = m;
        int ans = -1;
        while (low<=high){
            int mid = (low+high)/2;
            long x=1;
            for (int i =0;i<n;i++){
                x = x*mid;
                if (x>m) break;
            }
            if (x==m) {
                ans = mid;
                break;
            }
            else if (x>m) high =mid-1;
            else low = mid+1;
        }
        return ans;
        // Code here.
    }
    
};
```
