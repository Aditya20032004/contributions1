# DAY 26
## Trapping rainwater
### Optimal approach
```cpp
class Solution {
public:
    int trap(vector<int>& h) {
        int l=0,r=h.size()-1;
        int res=0;
        int left_max=0,right_max=0;
        while (l<=r){
            if (h[l]<=h[r]){
                if (h[l]>=left_max) left_max = h[l];
                else res+=(left_max-h[l]);
                l++;
            }
            else{
                if (h[r]>=right_max) right_max = h[r];
                else res+=(right_max-h[r]);
                r--;
            }
        }      
        return res;
    }
};
```
