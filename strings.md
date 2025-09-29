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
### Largest Odd Number in String(You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.)
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
### Write a function to find the longest common prefix string amongst an array of strings.
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

# Day 47
## Rotate String
### Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size()==goal.size() && (s+s).find(goal)!=string::npos;        
    }
};
```

# Day48
##  Valid Anagram
### Given two strings s and t, return true if t is an anagram of s, and false otherwise.
```cpp
class Solution {
public:
    bool isAnagram(string str1, string str2) {
        if (str1.length()!=str2.length()) return false;
        int freq[26]={0};
        for (int i=0;i<str1.length();i++){
            freq[str1[i]-'a']++;
            freq[str2[i]-'a']--;
        }        
        for (int i=0;i<26;i++){
            if (freq[i]!=0) return false;
        }
        return true;
    }
};
```

# Day 49
## Sort characters by frequency
### Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
```cpp
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        for (auto it:s) mpp[it]++;
        vector<pair<char,int>> vec(mpp.begin(),mpp.end());
        sort(vec.begin(),vec.end(),[](auto& a, auto& b){
            return a.second>b.second || (a.second==b.second && a.first<b.first);
        });

        string res;
        for (auto it:vec){
            for(int i=0;i<it.second;i++) res+=it.first;
        }
        return res;
    }
};
```

# Day 50
## Maximum Nesting Depth of the Parentheses
```cpp
class Solution {
public:
    int maxDepth(string s) {;
        int count=0;
        int res=0;
        for (char c:s){
            if (c=='(' ) count++;
            if (c==')' ) count--;
            res=max(count,res);
        }        
        return res;
    }
};
```

## Roman to Integer
```cpp
class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        map<char,int> mpp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        for (int i=0;i<s.size();i++){
            if (mpp[s[i]]<mpp[s[i+1]]) res-=mpp[s[i]];
            else res+=mpp[s[i]];
        }        
        return res;
    }
};
```
