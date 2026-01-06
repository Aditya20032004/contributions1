# Day 70
## [Check If All 1's Are at Least Length K Places Away](https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/?envType=daily-question&envId=2025-11-17)
#### Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.
```cpp
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last_one_index = -1;
        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] == 1) {
                if (last_one_index != -1) {
                    int distance = r - last_one_index - 1;   
                    if (distance < k) {
                        return false;
                    }
                }       
                last_one_index = r;
            }
        }      
        return true;
    }
};
```
# Day 75
## [Binary Prefix Divisible By 5](https://leetcode.com/problems/binary-prefix-divisible-by-5/description/?envType=daily-question&envId=2025-11-24)
#### You are given a binary array nums (0-indexed).We define xi as the number whose binary representation is the subarray nums[0..i] (from most-significant-bit to least-significant-bit).For example, if nums = [1,0,1], then x0 = 1, x1 = 2, and x2 = 5.Return an array of booleans answer where answer[i] is true if xi is divisible by 5.
```cpp
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int curr=0;
        /**res.reserve(nums.size());**/
        for(int i:nums){
            curr = ((curr<<1)+i)%5;
            res.push_back(curr==0);
        }
        return res;
    }
};
```
# Day 80
## [Maximum Running Time of N Computers](https://leetcode.com/problems/maximum-running-time-of-n-computers/description/?envType=daily-question&envId=2025-12-01)
#### You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.Note that the batteries cannot be recharged.Return the maximum number of minutes you can run all the n computers simultaneously.
```cpp
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long suma=0;
        for(int i:batteries) suma+=i;
        long long l =1,r=suma/n;
        while(l<r){
            long long extra =0;
            long long target = r-(r-l)/2;
            for(int i:batteries) extra+= min(target,(long long)i);
            if(extra>=(long long)n*target) l=target;
            else r = target-1;
        }        
        return l;
    }
};
```
# Day 81
## [Number of Trapezoids](https://leetcode.com/problems/count-number-of-trapezoids-i/description/?envType=daily-question&envId=2025-12-02)
#### You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.Return the number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.Since the answer may be very large, return it modulo 109 + 7.
```cpp
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long mod =1e9+7;
        unordered_map <int,int> freq;
        for(auto const &pt:points) freq[pt[1]]++;
        long long ans=0;
        long long ps=0;
        for(auto const&[y,count]:freq){
            long long e = ((long long)count*(count-1))/2;
            ans =(ans+ (e*ps))%mod;
            ps = (e+ps)%mod;
        }                
        return ans;
    }
};
```
# Day 82
## [Count Odd Numbers in an Interval Range](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/?envType=daily-question&envId=2025-12-07)
#### Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).
```cpp
class Solution {
public:
    int countOdds(int low, int high) {
        int count =0;
        for(int i=low;i<=high;i++){
            if (i%2!=0) count++;
        }        
        return count;
    }
};
```
```cpp
class Solution {
public:
    int countOdds(int low, int high) {
        return ((high+1)/2 - (low/2));        
    }
};
```

# Day 83
## [Count Square Sum Triples](https://leetcode.com/problems/count-square-sum-triples/description/?envType=daily-question&envId=2025-12-08)
#### A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.
```cpp
class Solution {
public:
    int countTriples(int n) {
        int count =0 ;
        for(int a=1;a<n;a++){
            for(int b= a+1;b<n;b++){
                double c= sqrt(a*a+ b*b);
                if(c<=n && c==(int)c) count+=2;
            }
        }
        return count;
        
    }
};

```
# Day 84
## [Count Special Triplets](https://leetcode.com/problems/count-special-triplets/description/?envType=daily-question&envId=2025-12-09)
#### You are given an integer array nums.A special triplet is defined as a triplet of indices (i, j, k) such that:
```cpp
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int mod = 1e9+7;
        unordered_map<int,long long> mppl,mppr;
        for(int i:nums) mppr[i]++;       
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            int mid = nums[i];
            int need = mid*2;
            mppr[mid]--;
            ans = (ans+(mppl[need]*mppr[need])%mod)%mod;
            mppl[mid]++;
        }
        return ans;
    }
};
```
```cpp
const int mod=1e9+7;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int M=100001, n=nums.size();
        int freq[M]={0}, prev[M]={0};
        for(int x: nums) freq[x]++;
        long long cnt=0;
        prev[nums[0]]++;
        for(int i=1; i<n-1; i++){
            const int x=nums[i], x2=x<<1;
            if (x2<M)
                cnt+=(long long)prev[x2]*(freq[x2]-prev[x2]-(x==0));
            prev[x]++;
        }
        return cnt%mod;
    }
};
```

# Day 87
## [Coupon Cdoe Validator](https://leetcode.com/problems/coupon-code-validator/description/?envType=daily-question&envId=2025-12-13)
#### You are given three arrays of length n that describe the properties of n coupons: code, businessLine, and isActive. The ith coupon has:
code[i]: a string representing the coupon identifier.businessLine[i]: a string denoting the business category of the coupon.
isActive[i]: a boolean indicating whether the coupon is currently active.A coupon is considered valid if all of the following conditions hold:code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".isActive[i] is true.Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order within each category.
```cpp
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> e1,g1,p1,r1;
        for(int i=0;i<code.size();i++){
            if (!isActive[i]) continue; /* Active or not **/
            string& bl = businessLine[i];
            if(bl!="electronics" && bl!="grocery" && bl!="pharmacy" && bl!="restaurant") continue;
            if(code[i].empty()) continue;
            bool ok = true;
            for(char c:code[i]){
                if(!isalnum(c) && c!='_'){
                    ok = false;
                    break;
                }  
            }
            if(!ok) continue;
            if(bl[0]=='e') e1.push_back(code[i]);
            if(bl[0]=='g') g1.push_back(code[i]);
            if(bl[0]=='p') p1.push_back(code[i]);
            if(bl[0]=='r') r1.push_back(code[i]);            
        }
        sort(e1.begin(),e1.end());
        sort(g1.begin(),g1.end());
        sort(p1.begin(),p1.end());
        sort(r1.begin(),r1.end());
        vector<string> res;
        res.insert(res.end(),e1.begin(),e1.end());
        res.insert(res.end(),g1.begin(),g1.end());
        res.insert(res.end(),p1.begin(),p1.end());
        res.insert(res.end(),r1.begin(),r1.end());
        return res;        
    }
};

```

# Day 88
## [Number of Smooth Descent Periods of a Stock](https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/submissions/1856292032/?envType=daily-question&envId=2025-12-15)
#### You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.Return the number of smooth descent periods.
```cpp
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 1;
        long long curr = 1;
        for(int i=1;i<prices.size();i++){
            if(prices[i]==(prices[i-1]-1)) curr++;
            else curr=1;
            ans+=curr;
        }        
        return ans;
    }
};
```

# Day 90
## [Buy and sell stock V](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/description/?envType=daily-question&envId=2025-12-17)
#### You are given an integer array prices where prices[i] is the price of a stock in dollars on the ith day, and an integer k.You are allowed to make at most k transactions, where each transaction can be either of the following:Normal transaction: Buy on day i, then sell on a later day j where i < j. You profit prices[j] - prices[i].Short selling transaction: Sell on day i, then buy back on a later day j where i < j. You profit prices[i] - prices[j].Note that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.Return the maximum total profit you can earn by making at most k transactions.
```cpp
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int K) {
        int n = prices.size();
        static long long t[1001][501][3]; 
        for(int k=0;k<=K;k++){
            t[n][k][0] = 0;
            t[n][k][1] = INT_MIN;
            t[n][k][2] = INT_MIN;
        }        
        for(int i=n-1;i>=0;i--){
            for(int k=0;k<=K;k++){
                t[i][k][0] = t[i+1][k][0];
                if(k>0){
                    t[i][k][0] = max(t[i][k][0], max(-prices[i]+t[i+1][k][1], prices[i]+t[i+1][k][2]));
                    t[i][k][1] = max(t[i][k][1], prices[i] + t[i+1][k-1][0]);
                    t[i][k][2] = max(t[i][k][2],-prices[i] + t[i+1][k-1][0]);
                }
                t[i][k][1] = t[i+1][k][1];
                if(k>0){
                    t[i][k][1] = max(t[i][k][1], prices[i] + t[i+1][k-1][0]);
                }
                t[i][k][2] = t[i+1][k][2];
                if(k>0){
                    t[i][k][2] = max(t[i][k][2], -prices[i] + t[i+1][k-1][0]);
                }
            }
        }
        return t[0][K][0];
    }
};
```
# Day 91
## [Buy an Sell Stock VI](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/description/?envType=daily-question&envId=2025-12-18)
#### You are given two integer arrays prices and strategy, where:prices[i] is the price of a given stock on the ith day.strategy[i] represents a trading action on the ith day, where:-1 indicates buying one unit of the stock.0 indicates holding the stock.1 indicates selling one unit of the stock.You are also given an even integer k, and may perform at most one modification to strategy. A modification consists of:Selecting exactly k consecutive elements in strategy.Set the first k / 2 elements to 0 (hold).Set the last k / 2 elements to 1 (sell).The profit is defined as the sum of strategy[i] * prices[i] across all days.Return the maximum possible profit you can achieve.Note: There are no constraints on budget or stock ownership, so all buy and sell operations are feasible regardless of past actions.
```cpp
class Solution {
public:
    typedef long long ll;
    ll maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<ll> profit(n);
        ll actualprofit = 0;
        for(int i=0;i<n;i++){
            profit[i] = prices[i]*strategy[i];
            actualprofit+=profit[i];
        }
        ll modprof=0,origprof=0,maxgain=0;
        int i=0,j=0;
        while(j<n){
            origprof+=profit[j];
            if((j-i+1)>k/2){
                modprof+=prices[j];
            }
            if((j-i+1)>k){
                origprof-=profit[i];
                modprof-=prices[i+k/2];
                i++;
            }            
            if((j-i+1)==k){
                maxgain = max(maxgain,modprof-origprof);
            }
            j++;
        }
        return actualprofit+maxgain;
    }
};
```

# Day 93
## [Delete Columns To make SOrted II](https://leetcode.com/problems/delete-columns-to-make-sorted-ii/description/?envType=daily-question&envId=2025-12-21)
#### You are given an array of n strings strs, all of the same length.We may choose any deletion indices, and we delete all the characters in those indices for each string.For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].Suppose we chose a set of deletion indices answer such that after deletions, the final array has its elements in lexicographic order (i.e., strs[0] <= strs[1] <= strs[2] <= ... <= strs[n - 1]). Return the minimum possible value of answer.length.
```cpp
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),m= strs[0].size();
        bitset<100> isSorted=0,remove=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n-1;j++){
                if(strs[j][i]>strs[j+1][i] && isSorted[j]==0){
                    remove[i]=1;
                    break;
                }
            }
            if(remove[i]) continue;

            for(int j=0;j<n-1;j++){
                isSorted[j]=isSorted[j]|(strs[j][i]<strs[j+1][i]);
            }
        }
        return remove.count();
    }
};
```
# Day 94
## [Two Best Non Overlapping events](https://leetcode.com/problems/two-best-non-overlapping-events/description/?envType=daily-question&envId=2025-12-23)
#### You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.Return this maximum sum.Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at o
```cpp
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        /* input the value in maxSuffix array **/
        int n = events.size();
        sort(events.begin(),events.end());
        vector<int> maxSuf(n);            
        maxSuf[n-1] = events[n-1][2];
        for(int i=0;i<n-2;i++){
            maxSuf[i] = max(maxSuf[i+1], events[i][2]);
        }    
        int ans =0;
        /* now doing binary search */
        for(int i=0;i<n;i++){
            int currvalue =events[i][2];
            ans = max(ans,currvalue);
            int nextstart = events[i][1]+1;
            int l=i+1,r =n-1,idx =-1;
            while(l<=r){
                int mid =(r+l)/2;
                if(events[i][0]>=nextstart){
                    idx=mid;
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            if(idx!=-1){
                ans = max(ans,currvalue+maxSuf[idx]);
            }
        }
        return ans;
    }
};
```
# Day 95
## [Apple Distribution into Boxes](https://leetcode.com/problems/apple-redistribution-into-boxes/description/?envType=daily-question&envId=2025-12-24)
#### You are given an array apple of size n and an array capacity of size m.There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.Note that, apples from the same pack can be distributed into different boxes.
```cpp
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        int sum = accumulate(apple.begin(),apple.end(),0);
        int need=0;
        sort(capacity.begin(),capacity.end(),greater<int>());
        while(sum>0){
            sum-=capacity[need];
            need++;
        }        
        return need;
    }
};
```

# Day 96
## [Maximize Happiness of Selected Children](https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=daily-question&envId=2025-12-25)
#### You are given an array happiness of length n, and a positive integer k.There are n children standing in a queue, where the ith child has happiness value happiness[i]. You want to select k children from these n children in k turns.In each turn, when you select a chlld, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.
```cpp
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(),greater<int>());
        int turns=0;
        long long maxhappinesssum =0;
        for(int i=0;i<k;i++){
            maxhappinesssum+= max(happiness[i]-turns,0);
            turns++;
        }        
        return maxhappinesssum;
    }
};
```
# Day 98
## [Last Day Where You Can Still Cross](https://leetcode.com/problems/last-day-where-you-can-still-cross/description/?envType=daily-question&envId=2025-12-31)
#### There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.
```cpp
class Solution {
public:
    int ROW;
    int COL;
    vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
    bool DFS(vector<vector<int>>& grid,int i,int j){
        if(i<0 || j<0 || i>=ROW || j>=COL || grid[i][j]==1) return false;
        if(i==ROW-1) return true;
        grid[i][j]=1;
        for(auto &d:dir){
            int new_i=d[0]+i;
            int new_j=d[1]+j;
            if(DFS(grid,new_i,new_j)) return true;
        }
        return false;
    }
    bool cancross(vector<vector<int>>& cells,int mid){
        vector<vector<int>> grid(ROW,vector<int>(COL));
        for(int i=0;i<mid;i++){
            int x = cells[i][0]-1;
            int y=cells[i][1]-1;
            grid[x][y]=1;
        }
        for(int j=0;j<COL;j++){
            if(grid[0][j]==0 && DFS(grid,0,j)){
                return true;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROW=row;
        COL=col;
        int l=1;
        int r=cells.size()-1;
        int lastday=0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(cancross(cells,mid)){
                l=mid+1;
                lastday=mid;
            }
            else r=mid-1;
        }
        return lastday;
    }
};
```

# Day 99
## [Number of Ways to Paint N × 3 Grid](https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/?envType=daily-question&envId=2026-01-03)
#### You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.
```cpp
class Solution {
public:
    int numOfWays(int n) {
        long long A = 6;
        long long B = 6;
        long long MOD = 1e9+7;
        for(int i=2;i<=n;i++){
            int newA=(2*A+2*B)%MOD;
            int newB=(2*A+3*B)%MOD;
            A=newA;
            B=newB;
        }        
        return (A+B)%MOD;
    }
};
```

# Day 100
## [Four Divisors](https://leetcode.com/problems/four-divisors/description/?envType=daily-question&envId=2026-01-04)
#### Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.
```cpp
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int div_sum=0;
        for(int i:nums){
            int div_count=0,in_sum=0;
            for(int j=1;j*j<=i;j++){
                if(i%j==0){
                    int new_n = i/j;
                    if(new_n==j){
                        div_count++;
                        in_sum+= j;
                    }
                    else{
                        div_count+=2;
                        in_sum+=(j+new_n);
                    }
                    if(div_count>4) break;
                }  
            }
            if (div_count==4) div_sum+=in_sum;       
        }   
        return div_sum;     
    }
};
```

# Day 101
## [Maximum Matrix Sum](https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2026-01-05)
#### You are given an n x n integer matrix. You can do the following operation any number of times:Choose any two adjacent elements of matrix and multiply each of them by -1.Two elements are considered adjacent if and only if they share a border.Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.
```cpp
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int count=0, mini = INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0) count++;
                mini = min(mini,abs(matrix[i][j]));
            }
        }        
        if((count %2)==0) count=0;
        else count=1;
        return (sum-(2*mini)*count);
    }
};
```
# Day 102
## [Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=daily-question&envId=2026-01-06)
#### Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        long long maxi=-1e18;
        int cl=1,ans=1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            long long currsum=0;
            for(int i=0;i<size;i++){
                TreeNode* n=q.front();
                q.pop();
                currsum += n->val;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            if(maxi<currsum){
                maxi = currsum;
                ans=cl;
            }
            cl++;
        }
        return ans;        
    }
};
```
