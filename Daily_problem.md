# Day 70
## [Check If All 1's Are at Least Length K Places Away](https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/?envType=daily-question&envId=2025-11-17)
#### Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.
```cpp
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last_one_index = -1;
        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] == 1) {
                if (last_one_index != -1) {
                    int distance = r - last_one_index - 1;   
                    if (distance < k) {
                        return false;
                    }
                }       
                last_one_index = r;
            }
        }      
        return true;
    }
};
```
# Day 75
## [Binary Prefix Divisible By 5](https://leetcode.com/problems/binary-prefix-divisible-by-5/description/?envType=daily-question&envId=2025-11-24)
#### You are given a binary array nums (0-indexed).We define xi as the number whose binary representation is the subarray nums[0..i] (from most-significant-bit to least-significant-bit).For example, if nums = [1,0,1], then x0 = 1, x1 = 2, and x2 = 5.Return an array of booleans answer where answer[i] is true if xi is divisible by 5.
```cpp
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int curr=0;
        /**res.reserve(nums.size());**/
        for(int i:nums){
            curr = ((curr<<1)+i)%5;
            res.push_back(curr==0);
        }
        return res;
    }
};
```
# Day 80
## [Maximum Running Time of N Computers](https://leetcode.com/problems/maximum-running-time-of-n-computers/description/?envType=daily-question&envId=2025-12-01)
#### You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.Note that the batteries cannot be recharged.Return the maximum number of minutes you can run all the n computers simultaneously.
```cpp
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long suma=0;
        for(int i:batteries) suma+=i;
        long long l =1,r=suma/n;
        while(l<r){
            long long extra =0;
            long long target = r-(r-l)/2;
            for(int i:batteries) extra+= min(target,(long long)i);
            if(extra>=(long long)n*target) l=target;
            else r = target-1;
        }        
        return l;
    }
};
```
# Day 81
## [Number of Trapezoids](https://leetcode.com/problems/count-number-of-trapezoids-i/description/?envType=daily-question&envId=2025-12-02)
#### You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.Return the number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.Since the answer may be very large, return it modulo 109 + 7.
```cpp
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long mod =1e9+7;
        unordered_map <int,int> freq;
        for(auto const &pt:points) freq[pt[1]]++;
        long long ans=0;
        long long ps=0;
        for(auto const&[y,count]:freq){
            long long e = ((long long)count*(count-1))/2;
            ans =(ans+ (e*ps))%mod;
            ps = (e+ps)%mod;
        }                
        return ans;
    }
};
```
# Day 82
## [Count Odd Numbers in an Interval Range](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/?envType=daily-question&envId=2025-12-07)
#### Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).
```cpp
class Solution {
public:
    int countOdds(int low, int high) {
        int count =0;
        for(int i=low;i<=high;i++){
            if (i%2!=0) count++;
        }        
        return count;
    }
};
```
```cpp
class Solution {
public:
    int countOdds(int low, int high) {
        return ((high+1)/2 - (low/2));        
    }
};
```

# Day 83
## [Count Square Sum Triples](https://leetcode.com/problems/count-square-sum-triples/description/?envType=daily-question&envId=2025-12-08)
#### A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.
```cpp
class Solution {
public:
    int countTriples(int n) {
        int count =0 ;
        for(int a=1;a<n;a++){
            for(int b= a+1;b<n;b++){
                double c= sqrt(a*a+ b*b);
                if(c<=n && c==(int)c) count+=2;
            }
        }
        return count;
        
    }
};

```
# Day 84
## [Count Special Triplets](https://leetcode.com/problems/count-special-triplets/description/?envType=daily-question&envId=2025-12-09)
#### You are given an integer array nums.A special triplet is defined as a triplet of indices (i, j, k) such that:
```cpp
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int mod = 1e9+7;
        unordered_map<int,long long> mppl,mppr;
        for(int i:nums) mppr[i]++;       
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            int mid = nums[i];
            int need = mid*2;
            mppr[mid]--;
            ans = (ans+(mppl[need]*mppr[need])%mod)%mod;
            mppl[mid]++;
        }
        return ans;
    }
};
```
```cpp
const int mod=1e9+7;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int M=100001, n=nums.size();
        int freq[M]={0}, prev[M]={0};
        for(int x: nums) freq[x]++;
        long long cnt=0;
        prev[nums[0]]++;
        for(int i=1; i<n-1; i++){
            const int x=nums[i], x2=x<<1;
            if (x2<M)
                cnt+=(long long)prev[x2]*(freq[x2]-prev[x2]-(x==0));
            prev[x]++;
        }
        return cnt%mod;
    }
};
```
