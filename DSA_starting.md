# DSA
## DAY1- selection sort
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



##   Day2

### Merge sort:
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


## DAY3 


### (Quick Sort)

      class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if (low<high){
            int part_index = partition(arr,low,high);
            quickSort(arr,low,part_index-1);
            quickSort(arr,part_index+1,high);
        }
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];
        // code here
        int i = low;
        int j = high;
        while (i<=j){
            while (arr[i]<=pivot && i<=high){
                i++;
            }
            while (arr[j]>pivot && j>=low){
                j--;
            }
            if (i<j){
                int temp = arr[i];
                arr[i]= arr[j];
                arr[j]= temp;
            }          
        }
        int temp = arr[low];
        arr[low]= arr[j];
        arr[j]= temp;
        return j;
    }    
    vector<int> qs(vector<int>& arr){
        quickSort(arr,0,arr.size()-1);
        return arr;
    }
};


### Largest number in an array
class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int max = arr[0];
        for (int i = 0;i<arr.size();i++){
            if (max<arr[i]){
                max = arr[i];
            }
        }
        return max;
    }
};


