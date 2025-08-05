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
