# Day 41
## Remove Outermost Parentheses
### Optimized Approach
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

# Day42
##  Reverse Words in a String
### Optimized Approach
```cpp
 class Solution {
public:
    string reverseWords(string s) {
        string s1="",s2="";
        int l=0,r =s.size()-1;
        while (l<=r){
            char ch=s[l];
            if (ch!=' ') s1+=ch;
            else {
                if (s1!=""){
                    if (s2!="") s2=s1+" "+s2;
                    else s2=s1;
                    s1="";
                }
            } 
            l++;
        }   
        if (s1!=""){
                if (s2!="") s2=s1+" "+s2;
                else s2=s1;
        }
          
        return s2;
    }
};
```

# Day43
## Largest Odd Number in String(You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.)
### Optimized Approach
```cpp
class Solution {
public:
    string largestOddNumber(string num) {
        int last=num.size();
        while (last>=0){
            if ((num[last]-'0')%2 !=0){
                return num.substr(0,last+1);
            }
            last--;
        }        
        return "";
    }
};
```
