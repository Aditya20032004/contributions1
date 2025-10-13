# Day 54
## Pow(x, n)
### Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        long long N = n;
        
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double result = 1.0;
        double current_product = x;
        
        while (N > 0) {
            if (N % 2 == 1) {
                result *= current_product;
            }
            current_product *= current_product;
            N /= 2;
        }
        
        return result;
    }
};
```

# Day 55 
## [Count Good Numbers](https://leetcode.com/problems/count-good-numbers/description/)
### A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
```cpp
class Solution {
public:
    const int mod = 1e9 + 7;
    
    int countGoodNumbers(long long n) {
        return helper(0, n);
    }
    
    int helper(int pos, long long n) {
        if (pos == n) return 1;
        
        int result = 0;
        
        if (pos % 2 == 0) {
            int even[] = {0, 2, 4, 6, 8};
            for (int digit : even) {
                result = (result + helper(pos + 1, n)) % mod;
            }
        } else {
            int odd[] = {2, 3, 5, 7};
            for (int digit : odd) {
                result = (result + helper(pos + 1, n)) % mod;
            }
        }
        
        return result;
    }
};
```
# Day 55
## Generate Parentheses
### [Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.](https://leetcode.com/problems/generate-parentheses/)    
```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> str;
        backtrack("",0,0,n,str);
        return str;        
    }
    void backtrack(string curr,int open,int close,int n,vector<string>& str){
        if (curr.length()==2*n){
            str.push_back(curr);
            return;
        }
        if (open<n) backtrack(curr+"(",open+1,close,n,str);
        if (close<open) backtrack(curr+")",open,close+1,n,str);
    }
};
```

# Day 56
## Subsets
### [Subsets
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.](https://leetcode.com/problems/subsets/description/)
```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {   
        vector<vector<int>> res;
        vector<int> arr;
        solve(0,nums,arr,res);
        return res;
    }
    void solve(int i,vector<int>& nums,vector<int>& arr,vector<vector<int>>& res){
        if (i==nums.size()){
            res.push_back(arr);
            return;
        }
        arr.push_back(nums[i]);
        solve(i+1,nums,arr,res);
        arr.pop_back();
        solve(i+1,nums,arr,res);
    }
};
```
