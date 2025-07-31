# DAY23
## Power of 2 
### OPtimal Approach
```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n==0) return false;
        if (n<0) return false;
        if ((n & (n-1))==0){
            return true;
        }        
        else return false;
    }
};
```
## Divide two integer without using  '/' operator
### Optimal Approach
```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Overflow case
        }
        if (dividend == divisor) {
            return 1;
        }
        
        bool sign = (dividend >= 0) == (divisor >= 0); // Determine the sign of the result
        
        long long n = abs((long long)dividend); // Use long long to avoid overflow
        long long b = abs((long long)divisor);
        long long quotient = 0;
        
        while (n >= b) {
            int count = 0;
            while (n >= (b << (count + 1))) {
                count++;
            }
            quotient += (1LL << count); // Use 1LL to ensure long long type
            n -= (b << count);
        }
        
        if (quotient > INT_MAX) {
            return sign ? INT_MAX : INT_MIN;
        }
        
        return sign ? quotient : -quotient;
    }
};
```
