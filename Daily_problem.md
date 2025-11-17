# Day 70
## (Check If All 1's Are at Least Length K Places Away)[https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/?envType=daily-question&envId=2025-11-17]
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
