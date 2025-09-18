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
# Day 32
## Longest substring without repeating characters
### Better Approach ( O(n) )
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mpp;
        int l=0,r=0;
        int len=0;
        int n =s.size();
        while (r<n){
            if (mpp.find(s[r])!=mpp.end()){
                l = max(mpp[s[r]]+1,l);
            }
            mpp[s[r]]=r;
            len = max(len,r-l+1);
            r++;
        }       
        return len; 
    }
};
```
# Day 34
## longest repeating character with rewplacement
### Optimised Appoach
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxf=0;
        int l=0;
        int maxl=0;
        map<char,int> mpp;
        for (int r=0;r<n;r++){
            mpp[s[r]]++;
            maxf = max(maxf,mpp[s[r]]);
            if ((r-l+1)-maxf > k){
                mpp[s[l]]--;
                l++;
            }
            else maxl=max(maxl,r-l+1);
        }        
        return maxl;
    }
};
```

# Day 36
## Number of substrings contraining all 3 characters
### Optimised approach
```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        int arr[3]={-1,-1,-1};
        int count =0;
        int n=s.size();
        for (int i=0;i<n;i++){
            arr[s[i]-'a']=i;
            if (arr[0]!=-1 && arr[1]!=-1 && arr[2]!=-1){
                count+=(1+min(arr[0],min(arr[1],arr[2])));
            }
        }
    return count;   
    }
    
};
```

# DAY 37
## Optimized Approach
### MXIMUM POINTS YOU CAN OBTAIN FROM THE CARDS
```cpp
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0,rsum=0,maxsum=0,right_index=cardPoints.size()-1;
        for (int i=0;i<k;i++) lsum=lsum+cardPoints[i];
        maxsum=lsum;
        for (int i=k-1;i>=0;i--){
            lsum=lsum-cardPoints[i];
            rsum+=cardPoints[right_index];
            right_index--;
            maxsum=max(maxsum,lsum+rsum);
        }        
        return maxsum;
    }
};
```

# Day 38
## Optimized Approach
### Number of subarrays with K different integers
```cpp
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return freqcount(nums,k)-freqcount(nums,k-1);        
    }
    int freqcount(vector<int>& nums, int k ){
        int l = 0,r = 0,count = 0;
        unordered_map<int,int> mpp;
        int n= nums.size();
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size() > k){
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            count += (r-l+1);
            r++;
        }       
        return count;
    }
};
```
