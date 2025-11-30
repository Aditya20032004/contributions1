# Day 77
## [Assign Cookies](https://leetcode.com/problems/assign-cookies/description/)
#### Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        while(i<g.size() && j<s.size()){
            if(g[i]<=s[j]) i++;
            j++;
        }       
        return i; 
    }
};
```
# Day 78
## [Lemonade Change](https://leetcode.com/problems/lemonade-change/description/)
#### At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.Note that you do not have any change in hand at first.Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.
```cpp
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        for(int i:bills){
            if(i==5) five++;
            else if(i==10){
                if(five>0){
                    five--;
                    ten++;
                }
                else return false;
            }
            else {
                if(five>0 && ten>0) {
                    five--;
                    ten--;
                }
                else if(five>=3) five-=3;
                else return false;
            }
        }        
        return true;
    }
};
```

# Day 79
## [Valid parnethesis Checker](https://leetcode.com/problems/valid-parenthesis-string/description/)
#### Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.The following rules define a valid string:Any left parenthesis '(' must have a corresponding right parenthesis ')'.Any right parenthesis ')' must have a corresponding left parenthesis '('.Left parenthesis '(' must go before the corresponding right parenthesis ')'.'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
```cpp
class Solution {
public:
    bool checkValidString(string s) {
        int mini=0,maxi=0;
        for(char c:s){
            if (c=='('){
                mini++;
                maxi++;
            }
            else if(c==')'){
                mini--;
                maxi--;
            }
            else{
                mini--;
                maxi++;
            }
            if(maxi<0) return false;
            if (mini<0) mini = max(mini,0);
        }
        return true;
    }
};
```
