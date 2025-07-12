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
