# DSA
DAY1- selection sort
      class Solution {
      public:
          vector<int> selectionSort(vector<int>& nums) {
              for (int i = 0; i<nums.size()-1; i++){
                  int mini = i;
                  for (int j =i+1; j<nums.size();j++){
                      if (nums[j]<nums[mini]){
                          mini = j;
                      }
                  }
              int temp = nums[mini];
              nums[mini]= nums[i];
              nums[i]= temp;
              }     
              return nums;   
          }
      };

Bubble sort:
    class Solution {
        public:
              vector<int> bubbleSort(vector<int>& nums) {
                  for (int i = nums.size()-1; i>=0; i--){
                      for (int j = 0; j<=i-1;j++){
                          if (nums[j]>nums[j+1]{
                               int temp = nums[j];
                               nums[j]= nums[j+1];
                               nums[j+1]= temp;
                          }    
                      }
                    }                 
                  return nums;   
              }
          };

Insertion sort:
    void insertion_sort(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }



####    Day2

Merge sort:
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

