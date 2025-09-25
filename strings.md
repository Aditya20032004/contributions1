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

# Day 44
## Write a function to find the longest common prefix string amongst an array of strings.
### Optimal Approach
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[strs.size()-1];
        string res="";
        int mini=min(first.size(),last.size());
        for(int i=0;i<mini;i++){
            if (first[i]!=last[i]) break;
            res+=first[i];
        }
        return res;
    }
};

```
# Day 46
## Isomorphic Strings
### Approach
```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256]={0},m2[256]={0};
        int n=s.size();
        for(int i=0;i<n;i++){
            if (m1[s[i]]!=m2[t[i]]) return false;
            m1[s[i]]=i+1;
            m2[t[i]]=i+1;
        }     
        return true;  
    }
};
```
