class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        for (int i=0;i<n;i++){
            int mini=nums[i];
            int maxi=nums[i];
            for (int j=i;j<n;j++){
                maxi =max(nums[j],maxi);
                mini = min(nums[j],mini);
                res +=maxi-mini;
            }
        }      
        return res;  
    }
};