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
