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
        return mini==0;
    }
};
```

# Day 85
## [Jump Game 2](https://leetcode.com/problems/jump-game-ii/description/)
#### You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:0 <= j <= nums[i] and i + j < n.Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.
```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxi =0,curr=0,jump=0;
        for(int i=0;i<nums.size()-1;++i){
            maxi =max(maxi,i+nums[i]);
            if (i==curr){
                jump++;
                curr = maxi;
            }
        }    
        return jump;    
    }
};
```
# Day 86
## [Candy](https://leetcode.com/problems/candy/description/)
#### There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.You are giving candies to these children subjected to the following requirements:Each child must have at least one candy.Children with a higher rating get more candies than their neighbors.
```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> lr(n,1);
        int sum=0;        
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]) lr[i]=lr[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]) lr[i]=max(lr[i+1]+1,lr[i]);
        }
        for(int i=0;i<n;i++) sum+=lr[i];
        return sum;
    }
};
```

# Day 87
## [Insert Table](https://leetcode.com/problems/insert-interval/)
#### You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).Return intervals after the insertion.Note that you don't need to modify intervals in-place. You can make a new array and return it.
```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i=0;
        int n=intervals.size();
        while(i<n && newInterval[0]>intervals[i][1]){
            res.push_back(intervals[i]);
            i++;
        }
        while(i<n && newInterval[1]>=intervals[i][0]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }       
        res.push_back(newInterval);
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        } 
        return res;
    }
};
```
