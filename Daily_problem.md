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
