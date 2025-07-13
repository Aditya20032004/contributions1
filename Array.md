# Day4
 ## 2sum problem
  
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

## Sort an array of 0s, 1s and 2s
### Better Approach

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
### Optimal Approach( Dutch National Flag Algorithm )
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


# Day 5
## Majority element occuring more than n/2
### Using Hashing (map)(Better Approach)
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
'''
