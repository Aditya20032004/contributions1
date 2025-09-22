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
