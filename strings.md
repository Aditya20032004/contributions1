# Day 41
## Remove Outermost Parentheses
### OPtiized Approach
```cpp
class Solution {
public:
    string removeOuterParentheses(string s) {
        string t;
        int count=0;
        for (char c:s){
            if (c=='(' && count++>0) t+=c;
            if (c==')' && count-->1) t+=c;
        }        
        return t;
    }
};
```
