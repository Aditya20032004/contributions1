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
