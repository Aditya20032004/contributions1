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
## [Subsets](https://leetcode.com/problems/subsets/description/)
### Subsets
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
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
# Day 57
## [Combination Sum](https://leetcode.com/problems/combination-sum/)
### Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> uni;
        vector<int> res;
        findcomb(0,target,candidates,res,uni);
        return uni;        
    }
    void findcomb(int idx,int target,vector<int>& candidates,vector<int>& res,vector<vector<int>>& uni){
        if (idx==candidates.size()){
            if (target==0){
                uni.push_back(res);
            }
            return;
        }
        if (candidates[idx]<=target){
            res.push_back(candidates[idx]);
            findcomb(idx,target-candidates[idx],candidates,res,uni);
            res.pop_back();
        }
        findcomb(idx+1,target,candidates,res,uni);

    }
};
```
## [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/description/)
#### Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        findcomb(0,target,candidates,cur,res);
        return res;        
    }
    void findcomb(int idx,int target,vector<int>& candidates,vector<int>& cur,vector<vector<int>>& res){
        if (target==0){
            res.push_back(cur);
            return;        
        }
        for(int i=idx;i<candidates.size();i++){
            if (i>idx && candidates[i]==candidates[i-1]) continue;
            if (candidates[i]>target) break;
            cur.push_back(candidates[i]);
            findcomb(i+1,target-candidates[i],candidates,cur,res);
            cur.pop_back();
        }
    }
};
```

# Day 58
## [Subsets II](https://leetcode.com/problems/subsets-ii/description/)
#### Given an integer array nums that may contain duplicates, return all possible subsets (the power set).The solution set must not contain duplicate subsets. Return the solution in any order.
```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {      
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        subsethelp(0,nums,curr,res);  
        return res;
    }

    void subsethelp(int idx,vector<int>& nums,vector<int>& curr, vector<vector<int>>& res){
        res.push_back(curr);
        for(int i=idx;i<nums.size();i++){
            if (i!=idx && nums[i-1]==nums[i]) continue;
            curr.push_back(nums[i]);
            subsethelp(i+1,nums,curr,res);
            curr.pop_back();
        }
    }
};
```
# Day 59
## [Combination Sum III](https://leetcode.com/problems/combination-sum-iii/description/)
#### Find all valid combinations of k numbers that sum up to n such that the following conditions are true.Only numbers 1 through 9 are used.Each number is used at most once.
```cpp
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>> res;
       vector<int> curr;
       sumhelp(n,1,curr,k,res);
       return res; 
    }
    void sumhelp(int sum,int last,vector<int>& curr,int k,vector<vector<int>>& res){
        if(sum==0 && curr.size()==k){
            res.push_back(curr);
            return;
        }
        if (sum<=0 || curr.size()>k){
            return;
        }
        for (int i = last;i<=9;i++){
            if (i<=sum){
                curr.push_back(i);
                sumhelp(sum-i,i+1,curr,k,res);
                curr.pop_back();
            }
            else break;
        }
    }
};
```
# Day 60
## [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)
#### Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
```cpp
    class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            string s="";
            vector<string> ans;
            digitscal(0,digits,s,ans,combos);
            return ans;        
        }
        void digitscal(int idx,string digits,string s,vector<string>& ans,string combos[]){
            if (idx==digits.size()){
                ans.push_back(s);
                return;
            }
            int digit = digits[idx]-'0';
            for (int i=0;i<combos[digit].size();i++){
                digitscal(idx+1,digits,s+combos[digit][i],ans,combos);            
            }
        }
    };
```

# Day 61
## [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/description/)
#### Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
```cpp
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        pushing(0,s,curr,res);
        return res;        
    }
    bool isPalind(string& s,int start,int end){
        while (start<end){
            if (s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void pushing(int idx, string& s,vector<string>& curr, vector<vector<string>>& res){
        if (s.length()==idx){
            res.push_back(curr);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if (isPalind(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                pushing(i+1,s,curr,res);
                curr.pop_back();
            }
        }
    }
};
```
# Day 62
## [Word Search](https://leetcode.com/problems/word-search/description/)
#### Given an m x n grid of characters board and a string word, return true if word exists in the grid.The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        int idx=0;
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (board[i][j]==word[idx]){
                    if (check(idx,i,j,board,word,row,col)){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
    bool check(int idx,int i, int j, vector<vector<char>>& board, string& word,int row, int col){
        if (idx==word.length()) return true;
        if (i<0 || j<0 || i==row || j==col || board[i][j]=='!' or board[i][j]!= word[idx]) return false;

        char c=board[i][j];
        board[i][j]='!';

        bool top = check(idx+1,i-1,j, board,  word,row,col);
        bool bottom = check(idx+1,i+1,j, board,  word,row,col);
        bool left = check(idx+1,i,j-1, board,  word,row,col);
        bool right = check(idx+1,i,j+1, board,  word,row,col);

        board[i][j]=c;

        return top||bottom||left||right;
    }
};

```

# Day 65
## N-Queens
#### The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
 ```cpp
class Solution {
public:
    void solve(int row,int n, vector<string>& board, vector<int>& cds, unordered_set<int>& posdiag, unordered_set<int>& negdiag, vector<vector<string>>& res){
        if (row==n){
            res.push_back(board);
            return;
        }
        for (int c=0;c<n;c++){
            if (posdiag.find(row+c)==posdiag.end() && negdiag.find(row-c)==negdiag.end() && cds[c]==0){
                board[row][c]='Q';
                cds[c]=1;
                posdiag.insert(row+c);
                negdiag.insert(row-c);
                solve(row+1,n,board,cds,posdiag,negdiag,res);
                board[row][c]='.';
                cds[c]=0;
                posdiag.erase(row+c);
                negdiag.erase(row-c);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> res;
        unordered_set<int> posdiag;
        unordered_set<int> negdiag;
        vector<int> cds(n,0);
        solve(0,n,board,cds,posdiag,negdiag,res);
        return res;        
    }
};
```

# Day 66
## Word Break
#### Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.Note that the same word in the dictionary may be reused multiple times in the segmentation.
```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<bool> dp(n+1,false);
        dp[0]=true;
        int maxlen=0;
        for(const string& word:wordDict) maxlen= max(maxlen,(int)word.size());

        for (int i=1;i<=n;i++){
            for (int j=max(0,i-maxlen);j<i;++j){
                if (dp[j] && dict.find(s.substr(j,i-j))!=dict.end()){
                    dp[i]=true;
                    break;
                }
            }
        }        
        return dp[n];
    }
};
```
# Day 68
## [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)
#### Write a program to solve a Sudoku puzzle by filling the empty cells.A sudoku solution must satisfy all of the following rules:Each of the digits 1-9 must occur exactly once in each row.Each of the digits 1-9 must occur exactly once in each column.Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
```cpp
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);        
    }
    bool isvalid(vector<vector<char>>& board, int row,int col,char c){
        for (int i=0;i<9;i++){
            if (board[i][col]==c) return false;
            if (board[row][i]==c) return false;
            if (board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for (int i=0;i<=8;i++){
            for (int j=0;j<=8;j++){
                if (board[i][j]=='.'){
                    for (char c='1';c<='9';c++){
                        if (isvalid(board,i,j,c)){
                            board[i][j]=c;
                            if (solve(board)) return true;
                            else board[i][j]='.';
                        }
                    }
                return false;
                }
            }
        }
        return true;
    }
    
};
```

