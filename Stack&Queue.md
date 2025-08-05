# DAY 24
## Implementing stack using queue
### Optimal Approach
```cpp
class MyStack {
public:
    MyStack() {
    }
    queue<int> n;
    void push(int x) {
        int s = n.size();
        n.push(x);
        for (int i=0;i<s;i++){
            n.push(n.front());
            n.pop();
        }        
    }
    
    int pop() {
        int q = n.front();
        n.pop();
        return q;    
    }
    
    int top() {
        return n.front();        
    }
    
    bool empty() {
        return n.empty();        
  }
}
```
    }
};

# DAY 25
## Check for valid parenthesis
### Optimal Appoach
```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (auto it:s){
            if (it=='(' || it=='{' || it=='[') st.push(it);
            else {
                if (st.size()==0) return false;
                char ch=st.top();
                st.pop();
                if ((it==')' && ch=='(') || (it=='}' && ch=='{') || (it==']' && ch=='[')) continue;
                else return false;
            }
        }        
        return st.empty();
    }
};
```

## Implement Min stack
### 1st approach
```cpp
class MinStack {
public:
    MinStack() {        
    }
    stack<pair<int,int>> st;
    
    void push(int val) {
        int m;
        if (st.empty()) m = val;
        else {
            m = min(st.top().second,val);
        }        
        st.push({val,m});
    }
    
    void pop() {
        st.pop();        
    }
    
    int top() {
        return st.top().first;        
    }
    
    int getMin() {
        return st.top().second;
    }

```
## Next greater than element
### Initial Approach
```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        vector<int> v(n, -1); // Initialize with size n and default value -1
        
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i % n]) {
                st.pop();
            }
            if (i < n) {
                if (!st.empty()) {
                    v[i] = st.top();
                }
            }
            st.push(nums2[i % n]);
        }
        return v;
    }
};
```
};
```
