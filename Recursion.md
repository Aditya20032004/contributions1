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
